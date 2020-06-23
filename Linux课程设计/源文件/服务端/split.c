 #include"chat.h"
/*
    src 源字符串的首地址(buf的地址) 
    separator 指定的分割字符
    dest 接收子字符串的数组
    num 分割后子字符串的个数
*/
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
         // *dest=pNext;
         // int h=strlen(pNext);
         // printf("%d\n",h);
         // *dest[h]='\0';
         // *dest++;
          ++count;
         pNext = (char *)strtok(NULL,separator);  //必须使用(char *)进行强制类型转换
    }  
    *num = count;
} 	


// void main(){
//    char *s[8]={0};
//    int n=0,m;
//    char buf[]="www.baidu.c424com,www.csdn.com,www.python.org";
//    info(buf,s);
//    printf("哈哈");
//    for(int j=0;j<n;j++){
//       printf("子字符串 %s",s[j]);
//       m=strlen(s[j]);
//       printf("字符串末尾%d %chhhh\n",m,s[j][m]);
//    }
//    int r=atof(s[1]);
//    printf("number: %d",r);
   // char r[6]={'s','f','f','\0','s','f'};
   // printf("%s\n长为%d",r,strlen(r));
// }
