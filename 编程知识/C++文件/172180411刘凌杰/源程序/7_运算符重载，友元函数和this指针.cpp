#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

class complex;
complex operator +(complex &a,complex &b);
complex operator -(complex &a,complex &b);
istream & operator>>(istream &is,complex &a);
ostream & operator<<(ostream &os,const complex &a);

class complex
{
private:
	int real,image;
public:
	complex()
	{
		real=0;
		image=0;
	}
	complex(int r,int i):real(r),image(i)
	{
	}
	friend istream & operator>>(istream &is,complex &a);
	friend ostream & operator<<(ostream &os,const complex &a);
	friend complex operator +(complex &a,complex &b);
	friend complex operator -(complex &a,complex &b);
	complex operator++(int);
	complex operator++();
	complex operator--(int);
	complex operator--();
	float fabs();//求复数的绝对值
	void save();//将复数信息保存为文件
};

istream &operator>>(istream &is,complex &a)
{
	cout<<"please input real and image:"<<endl;
	is>>a.real>>a.image;
	return is;
}

ostream &operator<<(ostream &os,const complex &a)
{
	if(a.image>0)
		os<<a.real<<"+"<<a.image<<"i"<<endl;
	else
		if(a.image<0)
			os<<a.real<<a.image<<"i"<<endl;
		else
			os<<a.real<<endl;
	return os;
}

complex operator +(complex &a,complex &b)
{
	return complex(a.real+b.real,a.image+b.real);
}

complex operator -(complex &a,complex &b)
{
	return complex(a.real-b.real,a.image-b.real);
}

complex complex::operator++(int)
{
	complex a=*this;
	real++;
	image++;
	return a;
}

complex complex::operator++()
{
	real++;
	image++;
	return *this;
}

complex complex::operator--(int)
{
	complex a=*this;
	real--;
	image--;
	return a;
}

complex complex::operator--()
{
	real--;
	image--;
	return *this;
}

float complex::fabs()
{
	return sqrt(pow(real,2)+pow(image,2));
}

void complex::save()
{
	ofstream  ofs("D:\\complex.dat",ios::binary);
	if(ofs)
	{
		ofs.write(reinterpret_cast<char*>(this),sizeof(*this));
		ofs.close();
		cout<<"save successful!"<<endl;
	}
	else
		cout<<"open fail!"<<endl;
}

int main()
{
	complex c(1,2);
	cout<<c;
	cout<<c.fabs()<<endl;
	c.save();
	system("pause");
	return 0;
}