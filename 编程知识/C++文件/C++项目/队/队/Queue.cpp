#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define QUEUESIZE 100

typedef int DataType;
typedef struct SeqQueue{
	DataType data[QUEUESIZE];
	int front;		//��ͷ��ɾ����
	int rear;		//��β�����룩
}SeqQueue;
//�ӵĳ�ʼ��
void lnitQueue(SeqQueue *q)
{
	q->front=0;
	q->rear=0;
}
//�ӵ����
void clearQueue(SeqQueue *q)
{
	q->front=0;
	q->rear=0;
}
//�ж϶��Ƿ�Ϊ��
bool queueEmpty(SeqQueue *q)
{
	return q->front==q->rear;
}
//�ж϶��Ƿ�Ϊ��
bool queueFull(SeqQueue *q)
{
	return q->front==(q->rear+1)%QUEUESIZE;
}
//��ȡ��ͷԪ��
bool getHead(SeqQueue *q,DataType *e)
{
	if(queueEmpty(q))
		return false;
	*e=q->data[q->front];
	return true;
}
//ȡ������Ԫ��
bool deQueue(SeqQueue *q,DataType *e)
{
	if(queueEmpty(q))
		return false;
	*e=q->data[q->front];
	q->front=(q->front+1)%QUEUESIZE;		//��front�������ʱ����������λ�û�ԭ���γ�ѭ������
	return true;
}
//��β���Ԫ��
bool enQueue(SeqQueue *q,DataType e)
{
	if(queueFull(q))
		return false;
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%QUEUESIZE;
	return true;
}
//��ͷɾ��Ԫ��
bool deleteQueue(SeqQueue *q)
{
	if(queueEmpty(q))
		return false;
	(q->front+1)%QUEUESIZE;
	return true;
}
//���Ԫ�ظ���
int queueLength(SeqQueue *q)
{
	return (q->rear)-(q->front);
}

void main()
{
	SeqQueue queue;
	int i;
	char ch;
	DataType e;
	lnitQueue(&queue);
	while(1)
	{
		cout<<"1.��β���Ԫ��"<<endl;
		cout<<"2.��ͷɾ��Ԫ��"<<endl;
		cout<<"3.��ȡ��ͷԪ��"<<endl;
		cout<<"4.ȡ����ͷԪ��"<<endl;
		cout<<"5.���ȫ��"<<endl;
		cout<<"6.��ȡ�ӵĳ���"<<endl;
		cout<<"0.�˳�����"<<endl;
		ch=getch();
		switch(ch)
		{
		case'1':
			cout<<"���������ݣ�";
			cin>>e;
			if(enQueue(&queue,e))
				cout<<"��ӳɹ���"<<endl;
			else
				cout<<"��������"<<endl;
			system("pause");
			system("cls");
			break;
		case'2':
			if(deleteQueue(&queue))
				cout<<"��ͷɾ���ɹ���"<<endl;
			else
				cout<<"�նӣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case'3':
			if(getHead(&queue,&e))
				cout<<"��ͷԪ��Ϊ�� "<<e<<endl;
			else
				cout<<"�նӣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case'4':
			if(deQueue(&queue,&e))
				cout<<"ȡ����ͷԪ�أ�"<<e<<endl;
			else
				cout<<"�նӣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case'5':
			clearQueue(&queue);
			cout<<"����ɹ���"<<endl;
			system("pause");
			system("cls");
			break;
		case'6':
			cout<<"�ӳ�Ϊ"<<queueLength(&queue)<<endl;
			system("pause");
			system("cls");
			break;
		case'0':
			exit(0);
		default:
			cout<<"�����������"<<endl;
			system("pause");
			system("cls");
		}
	}
}