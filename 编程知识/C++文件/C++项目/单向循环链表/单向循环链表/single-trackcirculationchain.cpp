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


//1��ȡ�ڵ����
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

//2��ȡָ���ڵ��ַ
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

//3����ڵ�
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
	Node *r=q->next;		//��¼��һ�ڵ�ĵ�ַ
	q->next=p;
	p->next=r;
	return true;
}

//4��ӡ��Ϣ����Ļ
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

//5ɾ��ָ���ڵ�
bool Delete(Node **rear,int pos)
{
	if(!rear)			//Ϊ��
	{
		return false;
	}
	if(getsize(*rear)==1)		//ֻ��һ���ڵ�
	{
		free(*rear);
		*rear=NULL;
		return true;
	}
	if(pos<=0||pos>getsize(*rear))	//�ж��Ƿ�Խ��
		return false;
	Node *p=getptr(*rear,pos-1);	//��ȡ��һ�ڵ��ָ��
	if(pos==1)						
	{
		p=getptr(*rear,getsize(*rear));
		*rear=(*rear)->next;
	}
	Node *q=p->next->next;		//��¼ɾ���ڵ����һָ��
	free(p->next);
	p->next=q;
	return true;
}

int main()
{
	Node *rear=NULL;
	int n;
	int data;
	cout<<"���������������"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"������� "<<i<<" ��������������"<<endl;
		cin>>data;
		insert(&rear,i,data);
	}
	cout<<""<<endl;
	cout<<""<<endl;
	system("pause");
	return 0;
}