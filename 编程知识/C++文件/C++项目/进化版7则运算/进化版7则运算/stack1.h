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
//栈类
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
			cout<<"内存申请失败！"<<endl;
			return ;
		}
		this->top=-1;
	}
	Stack(int n)
	{
		this->data=(DataType*)malloc(n*sizeof(DataType));
		if(!this->data)
		{
			cout<<"内存申请失败！"<<endl;
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
	bool emptyStack();	//判断栈是否为空
	bool fullStack();	//判断栈是否满
	DataType topStack();	//获取栈顶元素
	Status inputStack(DataType e);	//入栈
	Status popStack(DataType &e);	//出栈
};
//判断栈是否为空
template <typename DataType>
bool Stack<DataType>::emptyStack()
{
	return this->top==-1;
}
//判断栈是否满
template <typename DataType>
bool Stack<DataType>::fullStack()
{
	return this->top==SIZE-1;
}
//获取栈顶元素
template <typename DataType>
DataType Stack<DataType>::topStack()
{
	if(this->emptyStack())
		return ERROR;
	return this->data[this->top];
}
//入栈
template <typename DataType>
Status Stack<DataType>::inputStack(DataType e)
{
	if(this->fullStack())
		data=(DataType*)realloc(data,(top+SIZE)*sizeof(DataType));
	this->data[++this->top]=e; 
	return OK;
}
//出栈
template <typename DataType>
Status Stack<DataType>::popStack(DataType &e)
{
	if(this->emptyStack())
		return ERROR;
	e=this->data[this->top--];
	return OK;
}
