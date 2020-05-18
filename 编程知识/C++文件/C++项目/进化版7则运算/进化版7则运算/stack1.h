#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define SIZE 100
#define MAX 100
#define OK 0;
#define ERROR -1;
#define C '|'

int judge=-1;

typedef float Status;
template <typename DataType>
//ջ��
class Stack
{
private:
	int top;
	DataType *data;
public:
	Stack()
	{
		this->data=(DataType*)malloc(SIZE*sizeof(DataType));
		if(!this->data)
		{
			cout<<"�ڴ�����ʧ�ܣ�"<<endl;
			return ;
		}
		this->top=-1;
	}
	Stack(int n)
	{
		this->data=(DataType*)malloc(n*sizeof(DataType));
		if(!this->data)
		{
			cout<<"�ڴ�����ʧ�ܣ�"<<endl;
			return ;
		}
		this->top=-1;
	}
	~Stack()
	{
		free(this->data);
		this->data=NULL;
		this->top=-1;
	}
	bool emptyStack();	//�ж�ջ�Ƿ�Ϊ��
	bool fullStack();	//�ж�ջ�Ƿ���
	DataType topStack();	//��ȡջ��Ԫ��
	Status inputStack(DataType e);	//��ջ
	Status popStack(DataType &e);	//��ջ
};
//�ж�ջ�Ƿ�Ϊ��
template <typename DataType>
bool Stack<DataType>::emptyStack()
{
	return this->top==-1;
}
//�ж�ջ�Ƿ���
template <typename DataType>
bool Stack<DataType>::fullStack()
{
	return this->top==SIZE-1;
}
//��ȡջ��Ԫ��
template <typename DataType>
DataType Stack<DataType>::topStack()
{
	if(this->emptyStack())
		return ERROR;
	return this->data[this->top];
}
//��ջ
template <typename DataType>
Status Stack<DataType>::inputStack(DataType e)
{
	if(this->fullStack())
		data=(DataType*)realloc(data,(top+SIZE)*sizeof(DataType));
	this->data[++this->top]=e; 
	return OK;
}
//��ջ
template <typename DataType>
Status Stack<DataType>::popStack(DataType &e)
{
	if(this->emptyStack())
		return ERROR;
	e=this->data[this->top--];
	return OK;
}
