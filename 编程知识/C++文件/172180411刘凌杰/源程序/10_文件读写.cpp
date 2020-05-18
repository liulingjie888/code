#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define N 5

class Student
{
private:
	string name;
	float math,chinese,english;
public:
	Student()
	{
		name="Student";
		math=0;
		chinese=0;
		english=0;
	}
	Student(string n,float m,float c,float e)
	{
		name=n;
		math=m;
		chinese=c;
		english=e;
	}
	void printinfo()
	{
		cout<<name<<endl;
		cout<<math<<endl;
		cout<<chinese<<endl;
		cout<<english<<endl;
	}
	friend ifstream& operator>>(ifstream &ifs,Student a[]);
	friend ofstream& operator<<(ofstream &ofs,Student a[]);
};

ifstream& operator>>(ifstream &ifs, Student a[])
{
	ifs.open("D:\\student.dat",ios::binary);
	if(ifs)
	{
		for(int i=0;i<N;i++)
		{
			ifs.read(reinterpret_cast<char *>(a+i),sizeof(a[i]));
//			a[i].printinfo();
		}
		cout<<"read successful!"<<endl;
		ifs.close();
	}
	return ifs;
}

ofstream& operator<<(ofstream &ofs,Student a[])
{
	ofs.open("D:\\student.dat",ios::binary);
	if(ofs)
	{
		for(int i=0;i<N;i++)
		{
//			a[i].printinfo();
			ofs.write(reinterpret_cast<char *>(a+i),sizeof(a[i]));
		}
		cout<<"write successful!"<<endl;
		ofs.close();
	}
	return ofs;
}

int main()
{
	Student s[N]={Student("liu",66,66,66),Student("ling",77,77,77),Student("jie",88,88,88),Student("rao",99,99,99),Student("guang",100,100,100)};
	ofstream fs;
	fs<<s;
	Student a[5];
	ifstream ifs;
	ifs>>a;
	for(int i=0;i<5;i++)
	{
		a[i].printinfo();
	}
	system("pause");
	return 0;
}