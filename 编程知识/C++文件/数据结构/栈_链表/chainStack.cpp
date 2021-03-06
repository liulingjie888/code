#include<stdio.h>
#include<stdlib.h>
//
typedef int DataType;
//定义链表
typedef struct StackNode{		
	DataType data;
	struct StackNode *next;
}StackNode;
//定义链表栈
typedef struct LinkStack{		
	StackNode *top;
	int count;
}LinkStack;
//初始化栈
void lnitStack(LinkStack *s)
{
	s->top=NULL;
	s->count=0;
}
//判断栈是否为空
bool stackEmpty(LinkStack *s)
{
	return s->count==0;
}
//入栈
bool push(LinkStack *s,DataType e)	
{
	StackNode *n=(StackNode*)malloc(sizeof(StackNode));
	n->data=e;
	n->next=s->top;
	s->top=n;
	s->count++;
	return true;
}
//清栈
void clearStack(LinkStack *s)		
{
	StackNode *p=s->top;
	while(p)
	{
		StackNode *q=p;
		p=p->next;
		free(q);
	}
	s->count=0;
	s->top=NULL;
}
//获取栈顶元素
bool getTop(LinkStack *s,DataType *e)
{
	if(stackEmpty(s))
		return false;
	*e=s->top->data;
	return true;
}
//出栈
bool pop(LinkStack *s,DataType *e)
{
	if(stackEmpty(s))
		return false;
	*e=s->top->data;
	StackNode *p=s->top;
	s->top=p->next;
	free(p);
	s->count--;
	return true;
}
//获取栈元素个数
int getLength(LinkStack *s)
{
	return s->count;
}

void main()
{

}