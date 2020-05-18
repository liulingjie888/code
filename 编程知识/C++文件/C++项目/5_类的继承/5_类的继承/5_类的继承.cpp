// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define PI 3.1415926535
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

class circle:public point
{
private:
	float radius;
public:
	circle():point()
	{
		radius=0;
	}
	circle(float radius,float x,float y):point(x,y),radius(radius)
	{
	}
	float area()
	{
		return radius*radius*PI;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	circle c(2,2,2);
	cout<<c.area()<<c.getx()<<c.gety()<<endl;
	system("pause");
	return 0;
}

