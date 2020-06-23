#include "chat.h"

void *thrd_func(void *arg){
    int fd=(long)arg;
    int i;
    int len=0,rowLen=0,fieldLen=0;     //rowLen为消息数量,fieldLen为字段数量
    char *rows[1024]={0};       //记录消息
    char *fields[8]={0};        //记录字段
    char *t[2]={0};             //拆分时间
    char rec[10240]={'\0'};
    

    // printf("读线程创建成功\n");
    while(1){
        rec[0]='\0';
        len = recv(fd, rec, 10240, 0);
        // printf("%s\n",rec);
        rec[len] = '\0';

        if(strcmp(rec,"notMore")==0)
            continue;
        split(rec,"@",rows,&rowLen);
        for(i=0;i<rowLen;i++){
            split(rows[i],"#",fields,&fieldLen);
            split(fields[4]," ",t,&len);
            printf("======%s (%s):\n--%s\n",fields[2],t[1],fields[3]);
        }
        
    }
}
