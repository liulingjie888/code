#include "chat.h"

void main(void){

    printf("服务开始运行\n");
    startServer();

}

int startServer(){

    pthread_t clients_thread[MAX_CLIENT];
    int res;
    int number=0;

    int serverSocket;       //调用socket函数返回的文件描述符
    int clientSocket;       //客户套接字的描述符

    //声明两个套接字sockaddr_in结构体变量，分别表示客户端和服务器
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addr_len = sizeof(client_addr);

    //初始化锁
    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);
    pthread_mutex_init(&mutex3,NULL);

    //socket函数，失败返回-1
    //第一个参数表示使用的地址类型，一般都是ipv4，AF_INET
    //第二个参数表示套接字类型：tcp：面向连接的稳定数据传输SOCK_STREAM
    //第三个参数设置为0
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return 1;
    }
    
    //初始化服务器端的套接字
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;           //设置套接字为ipv4
    server_addr.sin_port = htons(SERVER_PORT);  //端口转换成网络字节序来设置监听端口
    // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//ip可是是本服务器的ip，也可以用宏INADDR_ANY代替，代表0.0.0.0，表明所有地址
    server_addr.sin_addr.s_addr=inet_addr("0.0.0.0");
    
    //对于bind，accept之类的函数，里面套接字参数都是需要强制转换成(struct sockaddr *)
    //绑定套接字
    if(bind(serverSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("#绑定套接字失败");
        return -1;
    }
 
    get_message_id();
    //设置服务器上的socket为监听状态
    if(listen(serverSocket, 5) < 0){
        perror("#监听失败");
        return -1;
    }
    printf("****监听端口: %d\n****-_-等待客户接入-_-\n",SERVER_PORT);
    while(1){
        //调用accept函数后，会进入阻塞状态
        //accept返回一个套接字的文件描述符，这样服务器端便有两个套接字的文件描述符，
        //serverSocket和client。
        //serverSocket仍然继续在监听状态，client则负责接收和发送数据
        //client_addr是一个传出参数，accept返回时，传出客户端的地址和端口号
        //addr_len是一个传入-传出参数，传入的是调用者提供的缓冲区的clientAddr的长度，以避免缓冲区溢出。
        //传出的是客户端地址结构体的实际长度。
        //出错返回-1
        
        clientSocket = accept(serverSocket, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
        if(clientSocket < 0){
            perror("#创建socket描述符失败");
            continue;
        }
       	
	if(online>=100){
		printf("在线人数已达上线%s",MAX_CLIENT);
		continue; 
	}
        //表达式：char *inet_ntoa (struct in_addr);inet_ntoa ip地址转换函数，将网络字节序IP转换为点分十进制IP
        printf("****^_^有客户连接啦,IP是 %s,Port是 %d\n", inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port));

        //开启客户接待线程
        res=pthread_create(&clients_thread[number],NULL,thrd_func,(void*)clientSocket);
	//记录下描述符
	pthread_mutex_lock(&mutex3);
	online++;
	pthread_mutex_unlock(&mutex3);        
	printf("****在线人数  %d\n",online);
	if(res!=0){
            printf("#%s 创建线程失败\n",inet_ntoa(client_addr.sin_addr));
            exit(res);
        }else{
            number=(++number)%MAX_CLIENT;
        }
        
    
    }
    close(serverSocket);

    return 0;
}
