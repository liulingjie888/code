#include<stdio.h>
#include<stdlib.h>
//
typedef int DataType;
//��������
typedef struct StackNode{		
	DataType data;
	struct StackNode *next;
}StackNode;
//��������ջ
typedef struct LinkStack{		
	StackNode *top;
	int count;
}LinkStack;
//��ʼ��ջ
void lnitStack(LinkStack *s)
{
	s->top=NULL;
	s->count=0;
}
//�ж�ջ�Ƿ�Ϊ��
bool stackEmpty(LinkStack *s)
{
	return s->count==0;
}
//��ջ
bool push(LinkStack *s,DataType e)	
{
	StackNode *n=(StackNode*)malloc(sizeof(StackNode));
	n->data=e;
	n->next=s->top;
	s->top=n;
	s->count++;
	return true;
}
//��ջ
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
//��ȡջ��Ԫ��
bool getTop(LinkStack *s,DataType *e)
{
	if(stackEmpty(s))
		return false;
	*e=s->top->data;
	return true;
}
//��ջ
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
//��ȡջԪ�ظ���
int getLength(LinkStack *s)
{
	return s->count;
}

void main()
{

}