#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 100

typedef int DataType;
typedef struct SeqQueue{
	DataType data[QUEUESIZE];
	int front;		//��ͷ��ɾ����
	int rear;		//��β�����룩
}SeqQueue;
//�ӵĳ�ʼ��
void initQueue(SeqQueue *q)
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
	*e-q->data[q->front];
	q->front=(q->front+1)%QUEUESIZE;		//��front�������ʱ����������λ�û�ԭ���γ�ѭ������
	return true;
}
//��β���Ԫ��
bool enQueue(SeqQueue *q,DataType e)
{
	if(queueFull(q))
		return false;
	q->data[q->rear]=e;
	q->rear=(q->rear)%QUEUESIZE;
	return true;
}\
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
	return (q->rear)-(q->front)+1;
}

void main()
{
	system("pause");
}