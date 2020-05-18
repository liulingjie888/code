// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class point
{
private:
	float x,y;
public:
	point():x(0),y(0)
	{
	}
	point(float x,float y):x(x),y(y)
	{
	}
	point(point &a)
	{
		x=a.x;
		y=a.y;
	}
	~point()
	{
	}
	float getx()
	{
		return x;
	}
	float gety()
	{
		return y;
	}
	void setx(float x)
	{
		this->x=x;
	}
	void sety(float y)
	{
		this->y=y;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	const int N=10;
	point *p= new point[N];
	for(int i=0;i<N;i++)
	{
		p[i].setx(i);
		(p+i)->sety(i);
		cout<<"("<<p[i].getx()<<","<<(p+i)->gety()<<")"<<endl;
	}
	delete []p;
	system("pause");
	return 0;
}

