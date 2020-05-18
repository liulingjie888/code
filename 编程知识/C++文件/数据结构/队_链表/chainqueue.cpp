#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int DataType;
//��������
typedef struct Qnode
{
	DataType data;
	struct Qnode *next;
}Qnode;
 //��������
typedef struct LinkQueue
{
	Qnode *front;
	Qnode *rear;
	int count;
}LinkQueue;

//�ж϶��Ƿ�Ϊ��
bool queueEmpty(LinkQueue *q)
{
	return q->front==NULL;
}

//�����Ԫ��
void clearQueue(LinkQueue *q)
{
	Qnode *p=q->front;
	while(p->next)
	{
		Qnode *r=p->next;
		free(p);
		p=r;
	}
	q->front=q->rear=NULL;
	q->count=0;
}

//��ʼ����
void initQueue(LinkQueue *q)
{
	if(!queueEmpty(q))
		clearQueue(q);
	q->front=q->rear=NULL;
	q->count=0;
}

//��β���Ԫ��
bool enQueue(LinkQueue *q,DataType e)
{
	Qnode *p=(Qnode*)malloc(sizeof(Qnode));
	if(!p)
		return false;
	p->data=e;
	p->next=NULL;
	if(queueEmpty(q))
		q->front=p;
	else
		q->rear->next=p;
	q->rear=p;
	q->count++;
	return true;

}

//���׳���
bool enQueue(LinkQueue *q,DataType *e)
{
	if(queueEmpty(q))
		return false;
	Qnode *p=q->front;
	*e=p->data;
	q->front=p->next;
	free(p);
	q->count--;
	return true;
}

//��ȡ��Ԫ�ظ���
int getLength(LinkQueue *q)
{
	return q->count;
}

//��ʾ����Ϣ
void print(LinkQueue *q)
{
	if(queueEmpty(q))
	{
		printf("�ն�\n");
		return ;
	}
	Qnode *p=q->front;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

void main()
{
	LinkQueue q;
	q.front=NULL;
	DataType a;

	initQueue(&q);
	print(&q);
	cout<<"����"<<getLength(&q)<<endl;

	enQueue(&q,1);
	enQueue(&q,3);
	enQueue(&q,5);
	print(&q);
	cout<<"����"<<getLength(&q)<<endl;

	enQueue(&q,&a);
	cout<<a<<endl;
	print(&q);
	cout<<"����"<<getLength(&q)<<endl;

	clearQueue(&q);
	print(&q);
	cout<<"����"<<getLength(&q)<<endl;
	system("pause");
}