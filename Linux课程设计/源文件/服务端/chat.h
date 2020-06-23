#include<stdio.h>
#include<string.h>
#include<mysql/mysql.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include<pthread.h>

#define ROWS 15                     //结果集记录最大数量
#define FIELDS 10                   //结果集字段最大数量

#define SERVER_PORT 6666            //服务器端口
#define MAX_CLIENT 100              //连接人数

int clients_fd[MAX_CLIENT];     //存储客户们的socket文件描述符(线程安全)
int message_id;                     //消息的id(每次启动服务会获取数据库的消息数量来确定初始值,要保证线程安全)
int online;			    //在线人数(保证线程安全)

pthread_mutex_t mutex1,mutex2,mutex3;	    //互斥锁

int liu_mysql_conn(MYSQL **conn_prt);
int liu_mysql_query(MYSQL *conn_prt,char *query_str,char **result,int *mp,int *np);
int liu_mysql_query1(MYSQL *conn_prt,char *query_str,char *result,int *num);
int liu_mysql_update(MYSQL *conn_prt,char *query_str);
void liu_mysql_close(MYSQL *conn_prt);

 void login(int fd,MYSQL *conn_prt,char *message,char **info);
void send_message(int fd,MYSQL *conn_prt,char *message,char **info);
 void more_message(int fd,MYSQL *conn_prt,char *message);
 void get_message_id();
 
void *thrd_func(void *arg);

void split(char *src,const char *separator,char **dest,int *num);

int startServer();
