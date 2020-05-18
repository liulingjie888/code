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


//1.��ȡ������
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

//2.��ȡָ��λ�õ�Ԫ�ص�ַ
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

//3.��������
bool insert(Node **head,int pos,DataType data)
{
	if(pos>=1&&pos<=getsize(*head)+1)		//�ж��Ƿ�Խ��
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		if(pos==1)					//��������ǰ��ʱ
		{
			p->next=*head;
			*head=p;
			return true;
		}
		if(!*head)
			if(pos==getsize(*head)+1)		//�����������
			{
				Node *q=*head;
				while(q->next)
				{
					q=q->next;
				}
				q->next=p;
				return true;
			}
		Node *q=getptr(*head,pos-1);//��ȡǰһ��Ԫ�ص�ָ��
		Node *r=q->next;
		q->next=p;//ǰһ��Ԫ�ص�ָ���Աָ���posԪ��
		p->next=r;
		return true;
	}
}

//4.ɾ������
bool earse(Node **head,int pos)
{
	if(pos<0||pos>getsize(*head))
		return false;
	Node *p=*head;
	if(pos==1)		//ɾ����һ��Ԫ�ص����
	{
		*head=(*head)->next;
		free(p);
		p=NULL;
		return true;
	}
	p=getptr(*head,pos-1);		//ָ���һԪ��
	Node *q=p->next->next;		//ָ�����Ԫ��
	free(p->next);			//ָ��ڶ�Ԫ��
	p->next=q;				//�ص㣨�ñ�һ��ֵҪͨ��ָ�����ֵ���ı䣩
	return true;
}

//5.������
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

//6.������������
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

//7.��������
void destroylist(Node **head)//����ָ���ָ��ᷢ������
{
	Node *p=*head;
	while(p)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
}

//8.����
bool sort(Node *head)
{
	if(!head||!head->next)	//ð������(�Ӵ�С��
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
	while(p->next)			//ѡ������(��С����
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

//9.��ֵ
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

//��ʾ����
void print(Node *head)
{
	if(!head)
	{
		printf("������\n");
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