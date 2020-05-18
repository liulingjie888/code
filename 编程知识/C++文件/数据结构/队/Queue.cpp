#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 100

typedef int DataType;
typedef struct SeqQueue{
	DataType data[QUEUESIZE];
	int front;		//队头（删除）
	int rear;		//队尾（插入）
}SeqQueue;
//队的初始化
void initQueue(SeqQueue *q)
{
	q->front=0;
	q->rear=0;
}
//队的清除
void clearQueue(SeqQueue *q)
{
	q->front=0;
	q->rear=0;
}
//判断队是否为空
bool queueEmpty(SeqQueue *q)
{
	return q->front==q->rear;
}
//判断队是否为满
bool queueFull(SeqQueue *q)
{
	return q->front==(q->rear+1)%QUEUESIZE;
}
//获取队头元素
bool getHead(SeqQueue *q,DataType *e)
{
	if(queueEmpty(q))
		return false;
	*e=q->data[q->front];
	return true;
}
//取出队首元素
bool deQueue(SeqQueue *q,DataType *e)
{
	if(queueEmpty(q))
		return false;
	*e-q->data[q->front];
	q->front=(q->front+1)%QUEUESIZE;		//当front溢出数组时，进行数组位置还原，形成循环队列
	return true;
}
//队尾添加元素
bool enQueue(SeqQueue *q,DataType e)
{
	if(queueFull(q))
		return false;
	q->data[q->rear]=e;
	q->rear=(q->rear)%QUEUESIZE;
	return true;
}\
//队头删除元素
bool deleteQueue(SeqQueue *q)
{
	if(queueEmpty(q))
		return false;
	(q->front+1)%QUEUESIZE;
	return true;
}
//求队元素个数
int queueLength(SeqQueue *q)
{
	return (q->rear)-(q->front)+1;
}

void main()
{
	system("pause");
}