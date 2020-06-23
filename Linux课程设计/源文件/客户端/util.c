#include"chat.h"

void get_time(char* t,int i){
    // char len[20] = {0};
    time_t timep;
    time(&timep);
    struct tm *p;
    p = gmtime(&timep);
    if(i==0)
        snprintf(t, 20, "%d-%d-%dT%d:%d:%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
    else
        snprintf(t, 20, "%d:%d:%d", 8 + p->tm_hour, p->tm_min, p->tm_sec);
}



void split(char *src,const char *separator,char **dest,int *num) {

     char *pNext;
     int count = 0;
     if (src == NULL || strlen(src) == 0) //如果传入的地址为空或长度为0，直接终止 
        return;
     if (separator == NULL || strlen(separator) == 0) //如未指定分割的字符串，直接终止 
        return;
     pNext = (char *)strtok(src,separator); //必须使用(char *)进行强制类型转换(虽然不写有的编译器中不会出现指针错误)
     while(pNext != NULL) {
          *dest++ = pNext;
          ++count;
         pNext = (char *)strtok(NULL,separator);  //必须使用(char *)进行强制类型转换
    }  
    *num = count;
} 	

// void main(void){
//     int len=0,i;
//     char *r[2]={0};
//     char str[]="撒疯狂就是否就方式";
//     split(str,";",r,&len);
//     for(i=0;i<len;i++){
//         printf("%s  %d\n",r[i],len);
//     }
    // printf("输入消息:\b\b\b\b\b\b\b\b\b");
    // printf("你好");
// }
