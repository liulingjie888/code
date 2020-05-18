//磁盘D中需串一个student.dat空文件
#include"stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class student;
istream &operator >>(istream &is,student &a);
ostream &operator <<(ostream &os,student &a);

class student
{
private:
	char  sex[10],Class[30],phone[20],name[20];
	long long int number;
	int num;
public:
	student(char *na="student",char *se="男",char *C="0000000",char *ph="00000000000",long long int nu=0)
	{
		strcpy_s(name,20,na);
		strcpy_s(sex,10,se);
		strcpy_s(Class,30,C);
		strcpy_s(phone,20,ph);
		number=nu;
	}		
	void alter(int n);									//信息修改
	friend void Classnum();							//获得班级信息
	friend void ranking();							//学生学号排名
	friend void classnum();							//查询各班人数
	friend void seekname();							//姓名查询
	friend void seeksex();							//性别查询
	friend void seekclass();						//班级查询
	friend void seekphone();						//电话查询
	friend void seeknumber();						//学号查询
	friend istream &operator >>(istream &is,student &a);
	friend ostream &operator <<(ostream &os,student &a);
};

student *a=new student[100];			//存放学生对象
string *classname=new string[30];		//存放班级名称
static int N=0;							//记录学生总数
static int cnum=0;								//分别记录班级数量

//暂停界面并刷新
void pause()
{
	getchar();
	cout<<"\n请按任意键继续......"<<endl;
	getchar();
	system("cls");
}

//将a数组中的数据保存到文件
void outinformation()
{
	ofstream ofs;
	ofs.open("D:\\student.dat",ios::binary);
	if(ofs)
	{
		for(int i=0;i<N;i++)
			ofs.write(reinterpret_cast<char *>(a+i),sizeof(a[i]));
		ofs.close();
	}
}

//获得文件里信息和学生数量N
void Number()
{
	int i=0;
	ifstream ifs;
	ifs.open("D:\\student.dat",ios::binary|ios::in);
	if(ifs)
	{
		while(!ifs.eof())
		{
			ifs.read(reinterpret_cast<char *>(a+i),sizeof(a[i]));
			i++;
		}
		ifs.close();
	}
	N=i-1;
}

//获得班级名称和数量
void Classnum()
{
	cnum=0;
	for(int i=0;i<N;i++)
	{
		if(i!=0)
		{
			bool judge=true;					//记录班级是否重复
			for(int j=0;j<cnum;j++)
			{
				if(a[i].Class==classname[j])
					judge=false;
			}
			if(judge)
			{
				classname[cnum++]=a[i].Class;
			}
		}
		else
		{
			classname[cnum++]=a[i].Class;
		}
	}
}

//信息的输入和保存
void Interface();
void input()
{
	char i='1';
	cin>>a[N];
	N++;
	cout<<"按任意键继续添加（退出请按0）"<<endl;
	getchar();
	i=getchar();
	system("cls");
	if(i=='0')
		Interface();
	else
		input();
}


//学号查找
void seeknumber()
{
	long long int numfind;
	bool n=true;
	cout<<"************************ 查  询 **************************"<<endl;
	cout<<"请输入你要查找学生的学号："<<endl;
	cin>>numfind;
	for(int i=0;i<N;i++)
	{
		if(numfind==a[i].number)
		{
			cout<<"你要查找的学生信息如下："<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)		
		cout<<"不存在该学生！"<<endl;
	pause();
}

//姓名查找
void seekname()
{
	string namefind;
	bool n=true;
	cout<<"************************ 查  询 **************************"<<endl;
	cout<<"请输入你要查找学生的姓名："<<endl;
	cin>>namefind;
	for(int i=0;i<N;i++)
	{
		if(namefind==a[i].name)
		{
			cout<<"你要查找的学生信息如下："<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"不存在该学生！"<<endl;
	pause();
}

//电话查找
void seekphone()
{
	string phonefind;
	bool n=true;
	cout<<"************************ 查  询 **************************"<<endl;
	cout<<"请输入你要查找学生的电话："<<endl;
	cin>>phonefind;
	for(int i=0;i<N;i++)
	{
		if(phonefind==a[i].phone)
		{
			cout<<"你要查找的学生信息如下："<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"不存在该学生！"<<endl;
	pause();
}

//班级筛选
void seekclass()
{
	Classnum();
	string classfind;
	bool n=true,m=false;
	cout<<"************************ 查  询 **************************"<<endl;
	cout<<"请输入你要查找学生的班级："<<endl;
	cin>>classfind;
	for(int i=0;i<cnum;i++)
	{
		if(classfind==classname[i])
			m=true;
	}
	if(m)
	{
		for(int i=0;i<N;i++)
		{
			if(classfind==a[i].Class)
			{
				cout<<"你要查找的学生信息如下："<<endl;
				cout<<a[i];
				n=false;
			}
		}
		if(n)
			cout<<"不存在该学生！"<<endl;
	}
	else
		cout<<"不存在该班级！"<<endl;
	pause();
}

//性别筛选
void seeksex()
{
	string sexfind;
	bool n=true;
	cout<<"************************ 查  询 **************************"<<endl;
	cout<<"请输入你要查找学生的性别："<<endl;
	cin>>sexfind;
	for(int i=0;i<N;i++)
	{
		if(sexfind==a[i].sex)
		{
			cout<<"你要查找的学生信息如下："<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"不存在该学生！"<<endl;
	pause();
}

void seek();

//根据信息查找学生
void studentseek()
{
	int i;
	while(1)
	{
		cout<<"************************ 查  询 **************************"<<endl;
		cout<<"        1、学号  2、姓名  3、 电话  4、班级  5、性别 "<<endl;
		cout<<"**********************************************************"<<endl;
		cout<<"请根据序号输入信息查找学生(返回请按0)："<<endl;
		cin>>i;
		system("cls");
		switch(i)
		{
		case 1:seeknumber();break;
		case 2:seekname();break;
		case 3:seekphone();break;
		case 4:seekclass();break;
		case 5:seeksex();break;
		case 0:seek();
		default:
			cout<<"************************ 查  询 **************************"<<endl;
			cout<<"                     输入序号无效！"<<endl;
			pause();
		}
	}

}

//查询各班学生数量
void classnum()
{
	Classnum();
	cout<<"************************ 查  询 **************************"<<endl;
	for(int j=0;j<cnum;j++)
	{
		int num=0;
		for(int i=0;i<N;i++)
		{
			if(a[i].Class==classname[j])
				num++;
		}
		cout<<"               （"<<classname[j]<<"）班的学生数量为 "<<num<<endl;
	}
	pause();
}

//查询信息
void Interface();						//功能菜单声名
void seek()
{
	if(N!=0)
	{
		int i;
		while(1)
		{
			cout<<"************************* 查  询 *************************"<<endl;
			cout<<"                   1、 学生信息查询"<<endl;
			cout<<"                   2、 各班人数查询"<<endl;
			cout<<"                   0、 返回功能界面"<<endl;
			cout<<"**********************************************************"<<endl;
			cout<<"请输入序号选择查询："<<endl;
			cin>>i;
			system("cls");
			switch(i)
			{
			case 1:studentseek();break;
			case 2:classnum();break;
			case 0:Interface();
			default:
				cout<<"************************ 查  询 **************************"<<endl;
				cout<<"                      输入序号无效!"<<endl;pause();
			}
		}
	}
	else
	{
		cout<<"************************ 查  询 **************************"<<endl;
		cout<<"                    无任何学生信息！"<<endl;
		pause();
	}
}

//选择学生信息修改
void students();				//函数声明
void alter1()
{
	int i;
	if(N!=0)
	{
		cout<<"************************ 修  改 *************************"<<endl;
		students();
		cout<<"\n请输入要修改学生的序号(退出请按0）："<<endl;
		cin>>i;
		if(i==0)
		{
			system("cls");
			Interface();
		}
		system("cls");
		if(i<=N&&i>0)
		{
			a[i-1].alter(i);
		}
		else
		{
			cout<<"*********************** 修  改 **************************"<<endl;
			cout<<"          你输入的序号不在学生总数范围之内！"<<endl;
			pause();
			alter1();
		}
	}
	else
	{
		cout<<"*********************** 修  改 ************************"<<endl;
		cout<<"                    无任何学生信息！"<<endl;
		pause();
     }
}

//学生对象信息修改
void student::alter(int n)
{
	char i;
	while(1)
	{
		cout<<"*********************** 修  改 **************************"<<endl;
		cout<<"                          该学生信息"<<endl;
		cout<<a[n-1];
		cout<<"*********************************************************"<<endl;
		cout<<"     1、姓名   2、 性别  3、 班级  4、电话  5、 学号 "<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"请输入序号选择你要修改的学生信息（返回请按0)："<<endl;
		cin>>i;
		switch(i)
		{
			case '1':cout<<"请输入你要改成的名字： ";cin>>name;cout<<"\n名字修改完成"<<endl;break;
			case '2':cout<<"请输入你要改成的性别： ";cin>>sex;cout<<"\n性别修改完成"<<endl;break;
			case '3':cout<<"请输入你要改成的班级： ";cin>>Class;cout<<"\n性别修改完成"<<endl;break;
			case '4':cout<<"请输入你要改成的电话： ";cin>>phone;cout<<"\n电话修改完成"<<endl;break;
			case '5':cout<<"请输入你要改成的学号： ";cin>>number;cout<<"\n学号修改完成"<<endl;break;
			case '0':system("cls");alter1();
			default:
				cout<<"输入序号无效！"<<endl;				
		}
		pause();
	}
}

//学生信息删除
void expurgate()
{
	if(N!=0)
	{
		int i;
		while(1)
		{
			if(N==0)
			{
				Interface();
			}
			cout<<"*********************** 删  除 ************************"<<endl;
			students();
			cout<<"请输入你要删除学生的序号(退出请按0）："<<endl;
			cin>>i;
			if(i<=N&&i>0)
			{
				for(int j=i;j<=N-1;j++)
				{
					a[j-1]=a[j];
				}
				N--;
				system("cls");
				students();
				cout<<"删除成功！请按任意键继续"<<endl;
				getchar();
				getchar();
				system("cls");

			}
			else
			{
				if(i==0)
				{
					system("cls");
					Interface();
				}
				else
				{
					cout<<"你输入的序号不在学生总数范围之内！"<<endl;
					pause();
					expurgate();
				}
			}
		}
	}
	else
	{
		cout<<"*********************** 删  除 ************************"<<endl;
		cout<<"                   无任何学生信息！"<<endl;
		pause();
	}
}

//根据学号将学生排列
void ranking()
{
	if(N!=0)
	{
		student t;
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<N-i-1;j++)
			{
				if(a[j].number>a[j+1].number)
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		cout<<"************************* 排  序 ************************"<<endl;
		students();
		cout<<"排序成功！请按任意键继续"<<endl;
		getchar();getchar();
	}
	else
	{
		cout<<"无任何学生信息！"<<endl;
		pause();
	
	}
}

//所有学生信息输出
void students()
{
	if(N==0)
		cout<<"               无学生信息！"<<endl;
	else
	{
		cout<<"                      所有学生信息"<<endl;

		for(int j=0;j<N;j++)
		{
			cout<<a[j];
		}
	}
}

//重载>>
istream &operator >>(istream &is,student &a)
{
	cout<<"*********************** 输  入 ************************"<<endl;
	cout<<"姓名:";
	is>>a.name;
	cout<<"性别:";
	is>>a.sex;
	cout<<"班级:";
	is>>a.Class;
	cout<<"电话:";
	is>>a.phone;
	cout<<"学号:";
	is>>a.number; 
	cout<<"输入完成！"<<endl;
	return is;
}
//重载<<
ostream &operator <<(ostream &os,student &a)
{
	os<<"*********************************************************"<<endl;
	os<<" 学号:                 "<<a.number<<endl;
	os<<" 姓名:                 "<<a.name<<endl;
	os<<" 性别:                 "<<a.sex<<endl;
	os<<" 班级:                 "<<a.Class<<endl;
	os<<" 电话:                 "<<a.phone<<endl;
	os<<"*********************************************************"<<endl;
	return os;
}

//功能界面
void Interface()
{
	int i;
	while(1)
	{
		cout<<"                  欢迎进入学生信息管理系统"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"                   1、  添加学生信息"<<endl;
		cout<<"                   2、  查询学生信息"<<endl;
		cout<<"                   3、  修改学生信息"<<endl;
		cout<<"                   4、  删除学生信息"<<endl;
		cout<<"                   5、  按学号将学生信息排序"<<endl;
		cout<<"                   6、  输出所有学生信息"<<endl;
		cout<<"                   0、  退出"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"请输入你想要操作的序号："<<endl;
		cin>>i;
		system("cls");
		switch(i)
		{
		case 1:input();break;
		case 2:seek();break;
		case 3:alter1();break;
		case 4:expurgate();break;
		case 5:ranking();break;
		case 6:students();pause();break;
		case 0:outinformation();exit(0);break;
		default:
			cout<<"输入序号无效！"<<endl;pause();
		}
		system("cls");
	}
}

int main()
{
	Number();
	Interface();
	system("pause");
	return 0;
}



