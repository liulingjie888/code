#include"stdafx.h"
#include<iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	int MAXSIZE;
	T *array;
	int count;
public:
	Stack()
	{
		MAXSIZE=0;
		count=0;
		array =new T[MAXSIZE];
	}
	Stack(int M)
	{
		MAXSIZE=M;
		count=0;
		array=new T[M];
	}
	~Stack()
	{
		delete []array;
		cout<<"delete successfully!"<<endl;
	}
	void push(T i);
	T top();
	T pop();
	bool empty();
	bool fill();
};
//��ջ
template<typename T>
void Stack<T>::push(T i)
{
	if(fill())
		cout<<"the Stack is full."<<endl;
	else
	{
		array[count++]=i;
	}
}
//��ջ
template<typename T>
T Stack<T>::top()
{
	if(empty())
	{
		cout<<"the Stack is empty."<<endl;
		return 0;
	}
	else
		return array[count-1];
}
//ջ��
template<typename T>
T Stack<T>::pop()
{
	if(empty())
	{
		cout<<"the Stack is empty."<<endl;
		return 0;
	}
	else
	{
		return array[--count];
	}
}
//�ж�ջ�Ƿ���
template<typename T>
bool Stack<T>::fill()
{
	return count==MAXSIZE;
}
//�ж�ջ�Ƿ�Ϊ��ջ
template<typename T>
bool Stack<T>::empty()
{
	return count==0;
}

int main()
{
	Stack<int> s(10);
	for(int i=1;i<=10;i++)
	{
		s.push(i);
	}
	cout<<"��ջ�� "<<s.pop()<<endl;
	cout<<"��ջ��ջ��Ϊ�� "<<s.top()<<endl;
	system("pause");
	return 0;
}