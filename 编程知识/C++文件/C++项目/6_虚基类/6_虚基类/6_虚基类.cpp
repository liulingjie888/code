// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class vehicle
{
private:
	int weight;
public:
	vehicle()
	{
		weight=0;
	}
	vehicle(int w):weight(w)
	{
	}
	~vehicle()
	{
	}
	virtual int display()
	{
		return weight;
	}
};

class car:virtual public vehicle
{
private:
	int personnum;
public:
	car():vehicle(),personnum(0)
	{
	}
	car(int w,int per):vehicle(w),personnum(per)
	{
	}
	~car()
	{
	}
	int display()
	{
		return personnum;
	}
};

class truck:virtual public vehicle
{
private:
	int load;
public:
	truck():vehicle()
	{
		load=0;
	}
	truck(int load,int w):vehicle(w),load(load)
	{
	}
	~truck()
	{
	}
	int display()
	{
		return load;
	}
};

class pickup: virtual public car, virtual public truck
{
public:
	pickup():car(),truck()
	{
	}
	pickup(int load,int per,int w):truck(load,w),car(w,per)
	{
	}
	int display()
	{
		cout<<"the personnum of car is "<<car::display()<<endl;
		cout<<"the load of truck is "<<truck::display()<<endl;
		return 0;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	pickup p(20,30,10);
	p.display();
	system("pause");
	return 0;
}

