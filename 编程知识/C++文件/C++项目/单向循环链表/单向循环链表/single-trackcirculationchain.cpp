#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;


//1获取节点个数
int getsize(Node *rear)
{
	int size=0;
	if(rear)
	{
		Node *p=rear->next;
		while(p!=rear)
		{
			size++;
			p=p->next;
		}
		size++;
	}
	return size;
}

//2获取指定节点地址
Node *getptr(Node *rear,int pos)
{
	if(!rear)
		return NULL;
	if(pos<=0&&pos>getsize(rear))
		return NULL;
	Node *p=rear;
	for(int i=1;i<pos;i++)
	{
		p=p->next;
	}
	return p;
}

//3插入节点
bool insert(Node **rear,int pos,DataType data)
{
	if(!*rear)
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		*rear=p;
		p->next=*rear;
		return true;
	}
	if(pos<=0||pos>getsize(*rear))
		return false;
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=data;
	Node *q=getptr(*rear,pos);
	Node *r=q->next;		//记录下一节点的地址
	q->next=p;
	p->next=r;
	return true;
}

//4打印信息到屏幕
void print(Node *rear)
{
	if(!rear)
		return ;
	Node *p=rear->next;
	cout<<rear->data<<endl;
	while(p!=rear)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

//5删除指定节点
bool Delete(Node **rear,int pos)
{
	if(!rear)			//为空
	{
		return false;
	}
	if(getsize(*rear)==1)		//只有一个节点
	{
		free(*rear);
		*rear=NULL;
		return true;
	}
	if(pos<=0||pos>getsize(*rear))	//判断是否越界
		return false;
	Node *p=getptr(*rear,pos-1);	//获取上一节点的指针
	if(pos==1)						
	{
		p=getptr(*rear,getsize(*rear));
		*rear=(*rear)->next;
	}
	Node *q=p->next->next;		//记录删除节点的下一指针
	free(p->next);
	p->next=q;
	return true;
}

int main()
{
	Node *rear=NULL;
	int n;
	int data;
	cout<<"请输入密码个数："<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"请输入第 "<<i<<" 个密码生成数："<<endl;
		cin>>data;
		insert(&rear,i,data);
	}
	cout<<""<<endl;
	cout<<""<<endl;
	system("pause");
	return 0;
}