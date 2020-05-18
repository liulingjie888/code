// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class book
{
private:
	string name;
	float price;
	static float allprice,number;
public:
	book()
	{
		name="book";
		price=0;
		number++;
	}
	book(string name,float price):name(name),price(price)
	{
		number++;
		allprice+=price;
	}
	float getallprice()
	{
		return allprice;
	}
	float getnum()
	{
		return number;
	}
};

float book::allprice=0;
float book::number=0;

int _tmain(int argc, _TCHAR* argv[])
{
	book b1("book1",2),b2("book2",3.2),b3("book3",5.4);
	cout<<b1.getallprice()<<endl;
	cout<<b2.getnum()<<endl;
	system("pause");
	return 0;
}

