#include"chat.h"

int main(){

    int res,i;
    pthread_t p_read;
    char send_time[20]={'\0'},show_time[20]={'\0'};
    char send_msg[1024]={'\0'},input_msg[512]={'\0'};
    char first_login[100];
    int clientSocket;               //客户端只需要一个套接字文件描述符，用于和服务器通信
   
   conn_server(&clientSocket);      //连接服务器

    //开启读线程
    res=pthread_create(&p_read,NULL,thrd_func,(void*)clientSocket);
    if(res!=0){
        printf("创建读线程失败\n");
        exit(res);
    }

    printf("=========欢迎使用linux多人聊天==========\n");
    printf("请输入用户名:\n");
    scanf("%s",name);

    sprintf(first_login,"1`noid#%s",name);                      //发送用户名
    send(clientSocket,first_login,strlen(first_login),0);

    while(1){
        memset(send_time,0,20);memset(show_time,0,20);
        memset(send_msg,0,1024);memset(input_msg,0,1024);
        get_time(send_time,0);get_time(show_time,1);            //设置时间

        scanf("%s",input_msg);                                  //输入

        if(strcmp(input_msg,"exit")==0){                        //判断是否推出
            send(clientSocket,"4",1,0);
            break;
        }
            
        //将消息发送
        sprintf(send_msg,"2`noid#%s#%s#%s#noimageUrl",name,input_msg,send_time);
        send(clientSocket,send_msg,strlen(send_msg),0);
        printf("======%s (%s):\n--%s\n",name,show_time,input_msg);

    }
    close(clientSocket);
    return 0;
}

//连接服务器
void conn_server(int *fd){
     struct sockaddr_in serverAddr;  //描述服务器的socket

    if((*fd= socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return ;
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6666);
    serverAddr.sin_addr.s_addr = inet_addr("106.52.216.126");    //指定服务器端的ip，本地测试：127.0.0.1;inet_addr()函数，将点分十进制IP转换成网络字节序IP
    
    if(connect(*fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){  //开始连接
        perror("connect fail");
        return ;
    }
    printf("连接到聊天服务器...\n");
}