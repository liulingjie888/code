#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define QUEUESIZE 100

typedef int DataType;
typedef struct SeqQueue{
	DataType data[QUEUESIZE];
	int front;		//队头（删除）
	int rear;		//队尾（插入）
}SeqQueue;
//队的初始化
void lnitQueue(SeqQueue *q)
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
	*e=q->data[q->front];
	q->front=(q->front+1)%QUEUESIZE;		//当front溢出数组时，进行数组位置还原，形成循环队列
	return true;
}
//队尾添加元素
bool enQueue(SeqQueue *q,DataType e)
{
	if(queueFull(q))
		return false;
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%QUEUESIZE;
	return true;
}
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
		cout<<"1.队尾添加元素"<<endl;
		cout<<"2.队头删除元素"<<endl;
		cout<<"3.获取队头元素"<<endl;
		cout<<"4.取出队头元素"<<endl;
		cout<<"5.清除全队"<<endl;
		cout<<"6.获取队的长度"<<endl;
		cout<<"0.退出程序"<<endl;
		ch=getch();
		switch(ch)
		{
		case'1':
			cout<<"请输入数据：";
			cin>>e;
			if(enQueue(&queue,e))
				cout<<"入队成功！"<<endl;
			else
				cout<<"队已满！"<<endl;
			system("pause");
			system("cls");
			break;
		case'2':
			if(deleteQueue(&queue))
				cout<<"队头删除成功！"<<endl;
			else
				cout<<"空队！"<<endl;
			system("pause");
			system("cls");
			break;
		case'3':
			if(getHead(&queue,&e))
				cout<<"队头元素为： "<<e<<endl;
			else
				cout<<"空队！"<<endl;
			system("pause");
			system("cls");
			break;
		case'4':
			if(deQueue(&queue,&e))
				cout<<"取出队头元素："<<e<<endl;
			else
				cout<<"空队！"<<endl;
			system("pause");
			system("cls");
			break;
		case'5':
			clearQueue(&queue);
			cout<<"清除成功！"<<endl;
			system("pause");
			system("cls");
			break;
		case'6':
			cout<<"队长为"<<queueLength(&queue)<<endl;
			system("pause");
			system("cls");
			break;
		case'0':
			exit(0);
		default:
			cout<<"输入序号有误！"<<endl;
			system("pause");
			system("cls");
		}
	}
}