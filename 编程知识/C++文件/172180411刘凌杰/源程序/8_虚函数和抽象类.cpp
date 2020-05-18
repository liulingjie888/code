#include"stdafx.h"
#include<iostream>
using namespace std;

#define PI 3.1415926535

class shape
{
public:
	virtual float area()=0;
	virtual float volume()=0;
	virtual void printinfo()=0;
};

template <typename T>
class point:public shape
{
private:
	 T x,y;
public:
	point()
	{
		x=0;
		y=0;
	}
	point(T x,T y):x(x),y(y)
	{
	}
	~point()
	{
	}
	float area()
	{
		return 0;
	}
	float volume()
	{
		return 0;
	}
	void printinfo()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};

template<typename T>
class circle:public point<T>
{
private:
	T r;
public:
	circle():r(0),point(0,0)
	{
	}
	circle(T r):r(r),point(0,0)
	{
	}
	circle(T r,T x,T y):r(r),point(r,y)
	~circle()
	{
	}
	T get_r()
	{
		return r;
	}
	float area()
	{
		return PI*r*r;
	}
	void printinfo()
	{
		cout<<"the radius is "<<r<<endl;
		cout<<"circle's area is "<<area()<<endl;
	}
};

template<typename T>
class cylinder:public circle<T>
{
private:
	T h;
public:
	cylinder():h(0),circle(0,0,0)
	{
	}
	cylinder(T h, T r):h(h),circle(r)
	{
	}
	cylinder(T h, T r,T x, T y):h(h),circle(r,x,y)
	{
	}
	~cylinder()
	{
	}
	float area()
	{
		return 2*circle::area()+2*PI*get_r()*h;
	}
	float volume()
	{
		return circle::area()*h;
	}
	void printinfo()
	{
		cout<<"the cylinder's high is "<<h<<endl;
		cout<<"the cylinder's area is "<<area()<<endl;
		cout<<"teh cylinder's volume is"<<volume()<<endl;
	}
};


int main()
{
	point<float> po(2,2);
	circle<float> c(2);
	cylinder<float> cy(2,2);
	shape *p=&po;
	p->printinfo();
	p=&c;
	p->printinfo();
	p=&cy;
	p->printinfo();
	system("pause");
	return 0;
}
/*ÒýÓÃ
int main()
{
	point<float> po(2,2);
	circle<float> c(2);
	cylinder<float> cy(2,2);
	shape &p=po;
	p.printinfo();
	shape &p1=c;
	p1.printinfo();
	shape &p2=cy;
	p2.printinfo();
	system("pause");
	return 0;
}*/