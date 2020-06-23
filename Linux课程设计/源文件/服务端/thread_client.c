#include"chat.h"

 void *thrd_func(void *arg){

    int fd=(long)arg;       //socket描述符
    int index;              //记录描述符的位置下标
    
    int dataLenth;          //接收字节的长度
    char buffer[1024]={'\0'};      //缓存接受字符串
    
    int messageLength;       //分割后的子字符串个数
    char *message[5] = {0};  //存放分割后的子字符串 
    
    int len,i;
    char *info[4]={0};       //存放id和用户名

    MYSQL *conn_prt;            //MYSQL句柄
    liu_mysql_conn(&conn_prt);  //连接数据库


    
    printf("****描述符%d创建线程成功!",fd);
    pthread_mutex_lock(&mutex2);   //加锁
    for(i=0;i<MAX_CLIENT;i++){      //存放socket描述符
        if(clients_fd[i]==0){
            clients_fd[i]=fd;
            index=i;
            break;
        }
    }
    pthread_mutex_unlock(&mutex2); //释放锁
    printf("****描述符%d加入成功,位置%d\n",fd,index);
    
    while(1){
        dataLenth= recv(fd, buffer, 1024, 0);       //接受客户的消息放入buffer中
        if(dataLenth < 0) {
                printf("%d recv null",fd);
                continue;
        }
        buffer[dataLenth] = '\0';

        if('4'==buffer[0]){                         //客户退出连接
            break;
        }

        //对消息拆分,分为消息类型和和内容
        split(buffer,"`",message,&messageLength);
        switch (message[0][0]){
            case '1':
                // split(message[1],"#",info,&len);
                login(fd,conn_prt,message[1],info);
                break;
            case '2':
                send_message(fd,conn_prt,message[1],info);
                break;
            case '3':
                more_message(fd,conn_prt,message[1]);
                break;
            default:
                break;
        }
    }
    printf("====用户 %s(%s) 下线\n",info[1],info[0]);
    close(fd);                      //关闭连接
    pthread_mutex_lock(&mutex2);
    clients_fd[index]=0;            //设置为空
    pthread_mutex_unlock(&mutex2);
    liu_mysql_close(conn_prt);      //关闭数据库连接

    pthread_mutex_lock(&mutex3);
    online--;
    printf("****在线人数  %d\n",online);
    pthread_mutex_unlock(&mutex3);
    pthread_exit(NULL);
 }

// 1:socket描述符
// 2:mysql连接
// 3:消息体
// 4:存放用户信息字符串数组
 void login(int fd,MYSQL *conn_prt,char *message,char **info){
    int num=0,len;
    char result[102400]={'\0'};
    char *sql_str="select * from messages order by number asc";

    split(message,"#",info,&len);
    printf("====用户 %s(%s) 上线啦\n",info[1],info[0]);
    //发送历史消息
    liu_mysql_query1(conn_prt,sql_str,result,&num);
    if(0!=num){
        send(fd, result, strlen(result), 0);
    } else{
        send(fd, "notMore", 7, 0);
    }
                
 }

//转发并存储用户消息
void send_message(int fd,MYSQL *conn_prt,char *message,char **info){
    int len=0,i;
    char *msg[4];
    char re_message[2048]={'\0'};
    char sql_str[2048]={'\0'};

    //存储到数据库
    split(message,"#",msg,&len);
    sprintf(sql_str,"insert into messages values(%d,'%s','%s','%s','%s','%s')",message_id,msg[0],msg[1],msg[2],msg[3],msg[4]);
    liu_mysql_update(conn_prt,sql_str);     //存储消息
    
    //发送给所有人
    sprintf(re_message,"%d#%s#%s#%s#%s#%s",message_id,msg[0],msg[1],msg[2],msg[3],msg[4]);
    printf("####用户 %s[%s] 发送了消息\n%s\n",info[1],info[0],msg[2]);
    for(i=0;i<MAX_CLIENT;i++){              
        if(clients_fd[i]!=fd && clients_fd[i]!=0){
            send(clients_fd[i], re_message, strlen(re_message), 0);
        }
    }
    
    pthread_mutex_lock(&mutex1);
    message_id++;   //消息序号+1
    pthread_mutex_unlock(&mutex1);
}

//请求更多消息
void more_message(int fd,MYSQL *conn_prt,char *message){
    int num=0;
    char sql_str[200]={'\0'};
    char result1[4096]={'\0'};

    sprintf(sql_str,"select * from messages where number<%s order by number desc limit 0,10",message);

    liu_mysql_query1(conn_prt,sql_str,result1,&num);
    if(0!=num)
        send(fd, result1, strlen(result1), 0);
    else{
        send(fd, "notMore", 7, 0);
    }
}

// 初始化消息序号
void get_message_id(){
     MYSQL *conn_prt;
     char result[16]={'\0'};
     int num=0;
     liu_mysql_conn(&conn_prt);
     liu_mysql_query1(conn_prt,"select count(*) from messages",result,&num);
     liu_mysql_close(conn_prt);
     message_id=atof(result);
     printf("****message_id初始化值 %d\n",message_id);
 }

