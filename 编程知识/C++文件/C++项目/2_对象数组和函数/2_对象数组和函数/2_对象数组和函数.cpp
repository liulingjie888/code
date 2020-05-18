// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int n=0;//记录学生人数

class student
{
private:
	string name;
	float score;
public:
	student()
	{
		name="student";
		score=0;
		n++;
	}
	student(string name,float score):name(name),score(score)
	{
	}
	student(student &a)
	{
		name=a.name;
		score=a.score;
		n++;
	}
	~student()
	{
	}
	friend void highestscore(student s[]);
};

void highestscore(student s[])
{
	int num;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if((s+j)->score>(s+j+1)->score)
			{
				num=(s+j)->score;
				(s+j)->score=(s+j+1)->score;
				(s+j+1)->score=num;
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<(s+i)->score<<"  ";
		cout<<endl;
	}*/
	cout<<"the highest score is "<<s[n-1].score<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	student s[5]={student("",3),student("",100),student("",34),student("",68),student("",54)};
	highestscore(s);
	system("pause");
	return 0;
}

