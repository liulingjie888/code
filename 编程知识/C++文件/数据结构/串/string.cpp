#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct String·
{
	char* data;
	int length;
	int Maxlength;
}String;

//获取串中字符串长度
int Length(String *S)
{
	return S->length;
}
//获取字符串长度
int length(char *s)
{
	int len=0;
	while(*s!='\0')
	{
		len++;
		s++;
	}
	return len;
}
//串初始化
void initString(String *S,char *str)
{
	S->length=S->Maxlength=length(str);
	S->data=(char *)malloc((S->Maxlength+1)*sizeof(char));
	int i=0;
	for(;i<S->length;i++)
	{
		S->data[i]=str[i];
	}
	S->data[i]='\0';
}
//销毁串
void destroyString(String *S)
{
	if(S->data==NULL)
	{
		return ;
	}
	free(S->data);
	S->data=NULL;
	S->length=S->Maxlength=0;
}
//清理串
void clearString(String *S)
{
	if(!S->data)
		return ;
	S->length=0;
}
//判断串是否为空
bool emptyString(String *S)
{
	return S->length==0;
}
//复制串1
void copyString(String *S,char *str)
{
	int len=length(str);
	if(S->Maxlength<len)
	{
		free(S->data);
		S->data=(char*)malloc((len+1)*sizeof(char));
		S->Maxlength=len;
	}
	for(int i=0;i<len;i++)
	{
		S->data[i]=str[i];
	}
	S->data[len]='\0';
	S->length=len;
}
//复制串2
void copyString(String *S,String *S1)
{
	if(S->Maxlength<S1->length)
	{
		free(S->data);
		S->data=(char*)malloc((S1->length+1)*sizeof(char));
		S->Maxlength=S1->length;
	}
	for(int i=0;i<S1->length;i++)
	{
		S->data[i]=S1->data[i];
	}
	S->data[S1->length]='\0';
	S->length=S1->length;
}
//根据ASCLL码比较串（精华）
int compareString(String *S1,String *S2)
{
	if(S1->data==NULL&&S2->data==NULL)
		return 0;
	if(S1->data==NULL&&S2->data!=NULL)
		return -1;
	if(S2->data==NULL&&S1->data!=NULL)
		return 1;
	if(S1->length==0)
		return (S2->length==0)?0:-1;
	if(S2->length==0)
		return (S1->length==0)?0:1;
	int i=0;
	while(true)					//精辟牛逼到冲天
	{
		if(S1->data[i]>S2->data[i])
			return 1;
		else if(S1->data[i]<S2->data[i])
			return -1;
		else if(S2->data[i]=='\0'&&S1->data[i]=='\0')
			return 0;
		i++;
	}
	
		return 0;
}
//将一串连接到另一串后面
void concatString(String *S,String *S1)
{
	if(!S1)
		return ;
	if(S->Maxlength<(S1->length+S->length))
	{
		char *p=S->data;
		S->data=(char*)malloc((S1->length+S->length+1)*sizeof(char));
		S->Maxlength=S1->length+S->length;
		for(int i=0;i<S->length;i++)
		{
			S->data[i]=p[i];
		}
		free(p);
	}
	for(int i=0;i<S1->length;i++)
	{
		S->data[S->length+i]=S1->data[i];
	}
	S->data[S->length+S1->length]='\0';
	S->length=S->length+S1->length;
}
//获取从pos开始长度为len的字串
char *subString(String *S,int pos,int len)
{
	if(pos<0||pos>=S->length)
		return "false!";
	if(pos+len>S->length||len<0)
		return "false!";
	char *p=(char*)malloc((len+1)*sizeof(char));
	for(int i=0;i<len;i++)
		p[i]=S->data[pos+i];
	p[len]='\0';
	return p;
}
//获取字串的首下标（精华）
int locateString(String *S,char *str,int pos=0/*从下标为pos元素开始查找*/)
{
	if(pos<0||pos>=S->length)
		return -1;
	int len=length(str);
	if(pos+len>S->length)
		return -1;
	for(int i=pos;i<=S->length-len;i++)
	{
		int j=0;
		for(;j<len;j++)
		{
			if(str[j]!=S->data[i+j])
				break;
			
		}
		if(j==len)
			return i;
	}
	return -1;
}
//插入子字符串（精华）
bool insertString(String *S,char *str,int pos)
{
	cout<<pos<<" "<<S->length<<endl;
	if(pos<0||pos>S->length)
		return false;
	int len=length(str);
	if(S->length+len>S->Maxlength)
	{
		char *p=S->data;
		S->data=(char*)malloc((S->length+len+1)*sizeof(char));
		S->Maxlength=S->length+len;
		for(int i=0;i<S->length;i++)
		{
			S->data[i]=p[i];
		}
		free(p);
	}
	for(int i=S->length+len-1;i>=pos+len;i--)//细品
	{
		S->data[i]=S->data[i-len];
	}
	for(int i=pos;i<pos+len;i++)
	{
		S->data[i]=str[i-pos];
	}
	S->data[S->length+len]='\0';
	S->length=len+S->length;
	return true;
}
//删除子字符串
bool deleteString(String *S,int pos,int len)
{
	if(pos<0||pos>=S->length)
		return false;
	if(pos+len>S->length)
		return false;
	for(int i=pos;i<S->length-len;i++)
	{
		S->data[i]=S->data[i+len];
	}
	S->data[S->length-len]='\0';
	cout<<S->length<<"删除 "<<len<<endl;
	S->length=S->length-len;
	return true;
}
//用新字符串替换旧子字符串
bool replaceString(String *S,char *oldstr,char *newstr)
{
	
	int i=locateString(S,oldstr);
	if(i<0)
		return false;
	int j=0;
	while(i>=0)
	{
		deleteString(S,i,length(oldstr));
		insertString(S,newstr,i);
		i=locateString(S,oldstr,i+length(newstr));
	}
	return true;
}
void main()
{
	String s,s1;
	initString(&s,"Hello world!");
	initString(&s1,"i lovle ylou.l.");
	cout<<s1.length<<""<<s.length<<endl;
	replaceString(&s1,".","a");
	cout<<s1.data<<endl;
	cout<<s1.length<<endl;
	cout<<Length(&s1)<<endl;
	system("pause");
}