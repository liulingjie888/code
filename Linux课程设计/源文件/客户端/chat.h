#include<stdio.h>
#include<string.h>
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

#define FIELDS 10;
#define SERVER_PORT 6667;

char name[30];

void *thrd_func(void *arg);
void split(char *src,const char *separator,char **dest,int *num);
void get_time(char* t,int i);
void conn_server(int *fd);