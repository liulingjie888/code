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


//1.获取链表长度
int getsize(Node *head)
{
	int n=0;
	while(head)
	{
		head=head->next;
		n++;
	}
	return n;
}

//2.获取指定位置的元素地址
Node* getptr(Node *head,int pos)
{
	Node *p=head;
	if(p==NULL||pos<=0||pos>getsize(head))
	{
		return NULL;
	}
	for(int i=1;i<pos;i++)
	{
		p=p->next;
	}
	return p;
	
}

//3.插入链表
bool insert(Node **head,int pos,DataType data)
{
	if(pos>=1&&pos<=getsize(*head)+1)		//判断是否越界
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		if(pos==1)					//插入在最前面时
		{
			p->next=*head;
			*head=p;
			return true;
		}
		if(!*head)
			if(pos==getsize(*head)+1)		//插入在最后面
			{
				Node *q=*head;
				while(q->next)
				{
					q=q->next;
				}
				q->next=p;
				return true;
			}
		Node *q=getptr(*head,pos-1);//获取前一个元素的指针
		Node *r=q->next;
		q->next=p;//前一个元素的指针成员指向第pos元素
		p->next=r;
		return true;
	}
}

//4.删除链表
bool earse(Node **head,int pos)
{
	if(pos<0||pos>getsize(*head))
		return false;
	Node *p=*head;
	if(pos==1)		//删除第一个元素的情况
	{
		*head=(*head)->next;
		free(p);
		p=NULL;
		return true;
	}
	p=getptr(*head,pos-1);		//指向第一元素
	Node *q=p->next->next;		//指向第三元素
	free(p->next);			//指向第二元素
	p->next=q;				//重点（该边一个值要通过指向这个值来改变）
	return true;
}

//5.链表倒置
void reverse(Node **head)
{
	if((!*head)||(!(*head)->next))
		return ;
	Node *p=*head;
	Node *q=p->next;
	Node *r=q->next;
	p->next=NULL;
	q->next=p;
	while(r)
	{
		p=q;
		q=r;
		r=q->next;
		q->next=p; 
	}
	q->next=p;
	*head=q;
}

//6.两个链表连接
void Union(Node **a,Node *d)
{
	if(!*a)
	{
		*a=d;
	}
	else
	{
		Node *p=*a;
		while(p->next)
		{
			p=p->next;
		}
		p->next=d;
	}
}

//7.销毁链表
void destroylist(Node **head)//不用指针的指针会发生错误
{
	Node *p=*head;
	while(p)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
}

//8.排序
bool sort(Node *head)
{
	if(!head||!head->next)	//冒泡排序法(从大到小）
		return false;
	Node* p=head;
	DataType a;
	int n=getsize(head)-1;
	for(int i=1;i<=n;i++)
	{
		Node* q=p;
		for(int j=i;j<=n;j++)
		{
			if(q->data<q->next->data)
			{
				a=q->data;
				q->data=q->next->data;
				q->next->data=a;
			}
			q=q->next;
		}
	}
	/*
	while(p->next)			//选择排序法(从小到大）
	{
		Node* q=p->next;
		while(q)
		{
			if((p->data)>(q->data))
			{
				a=p->data;
				p->data=q->data;
				q->data=a;
			}
			q=q->next;
		}
		p=p->next;
	}*/
	return true;
}

//9.换值
bool change(Node *head,int pos,DataType data)
{
	if(pos<0||pos>getsize(head)||head==NULL)
		return false;
	Node *p=head;
	for(int i=1;i<=pos-1;i++)
	{
		p=p->next;
	}
	p->data=data;
	return true;
}

//显示数据
void print(Node *head)
{
	if(!head)
	{
		printf("空链表！\n");
		return ;
	}
	Node *p=head;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

int main()
{
	Node *head=NULL;
	insert(&head,1,54);
	insert(&head,2,88);
	insert(&head,3,34);
	insert(&head,1,3);
	print(head);
	cout<<getsize(head)<<endl;
	system("pause");
	return 0;
}