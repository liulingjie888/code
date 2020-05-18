#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct String��
{
	char* data;
	int length;
	int Maxlength;
}String;

//��ȡ�����ַ�������
int Length(String *S)
{
	return S->length;
}
//��ȡ�ַ�������
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
//����ʼ��
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
//���ٴ�
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
//����
void clearString(String *S)
{
	if(!S->data)
		return ;
	S->length=0;
}
//�жϴ��Ƿ�Ϊ��
bool emptyString(String *S)
{
	return S->length==0;
}
//���ƴ�1
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
//���ƴ�2
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
//����ASCLL��Ƚϴ���������
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
	while(true)					//����ţ�Ƶ�����
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
//��һ�����ӵ���һ������
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
//��ȡ��pos��ʼ����Ϊlen���ִ�
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
//��ȡ�ִ������±꣨������
int locateString(String *S,char *str,int pos=0/*���±�ΪposԪ�ؿ�ʼ����*/)
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
//�������ַ�����������
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
	for(int i=S->length+len-1;i>=pos+len;i--)//ϸƷ
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
//ɾ�����ַ���
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
	cout<<S->length<<"ɾ�� "<<len<<endl;
	S->length=S->length-len;
	return true;
}
//�����ַ����滻�����ַ���
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