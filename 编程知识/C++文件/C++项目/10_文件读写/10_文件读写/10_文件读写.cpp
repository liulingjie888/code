//����D���贮һ��student.dat���ļ�
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
	student(char *na="student",char *se="��",char *C="0000000",char *ph="00000000000",long long int nu=0)
	{
		strcpy_s(name,20,na);
		strcpy_s(sex,10,se);
		strcpy_s(Class,30,C);
		strcpy_s(phone,20,ph);
		number=nu;
	}		
	void alter();									//��Ϣ�޸�
	friend void ranking();							//ѧ��ѧ������
	friend void classnum();							//��ѯ��������
	friend void seekname();							//������ѯ
	friend void seeksex();							//�Ա��ѯ
	friend void seekclass();						//�༶��ѯ
	friend void seekphone();						//�绰��ѯ
	friend void seeknumber();						//ѧ�Ų�ѯ
	friend istream &operator >>(istream &is,student &a);
	friend ostream &operator <<(ostream &os,student &a);
};

student *a=new student[100];			//���ѧ������
static int N=0;				//��¼ѧ������

//��ͣ���沢ˢ��
void pause()
{
	getchar();
	cout<<"\n�밴���������......"<<endl;
	getchar();
	system("cls");
}

//��a�����е����ݱ��浽�ļ�
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

//����ļ���ѧ������N
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

//��Ϣ������ͱ���
void input()
{
	cin>>a[N];
	N++;
	outinformation();
	pause();
}


//ѧ�Ų���
void seeknumber()
{
	long long int numfind;
	bool n=true;
	cout<<"��������Ҫ����ѧ����ѧ�ţ�"<<endl;
	cin>>numfind;
	for(int i=0;i<N;i++)
	{
		if(numfind==a[i].number)
		{
			cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)		
		cout<<"�����ڸ�ѧ����"<<endl;
	pause();
}

//��������
void seekname()
{
	string namefind;
	bool n=true;
	cout<<"��������Ҫ����ѧ����������"<<endl;
	cin>>namefind;
	for(int i=0;i<N;i++)
	{
		if(namefind==a[i].name)
		{
			cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"�����ڸ�ѧ����"<<endl;
	pause();
}

//�绰����
void seekphone()
{
	string phonefind;
	bool n=true;
	cout<<"��������Ҫ����ѧ���ĵ绰��"<<endl;
	cin>>phonefind;
	for(int i=0;i<N;i++)
	{
		if(phonefind==a[i].phone)
		{
			cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"�����ڸ�ѧ����"<<endl;
	pause();
}

//�༶ɸѡ
void seekclass()
{
	string classfind;
	bool n=true;
	cout<<"��������Ҫ����ѧ���İ༶��"<<endl;
	cin>>classfind;
	for(int i=0;i<N;i++)
	{
		if(classfind==a[i].Class)
		{
			cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"�����ڸ�ѧ����"<<endl;
	pause();
}

//�Ա�ɸѡ
void seeksex()
{
	string sexfind;
	bool n=true;
	cout<<"��������Ҫ����ѧ�����Ա�"<<endl;
	cin>>sexfind;
	for(int i=0;i<N;i++)
	{
		if(sexfind==a[i].sex)
		{
			cout<<"��Ҫ���ҵ�ѧ����Ϣ���£�"<<endl;
			cout<<a[i];
			n=false;
		}
	}
	if(n)
		cout<<"�����ڸ�ѧ����"<<endl;
	pause();
}

void seek();

//������Ϣ����ѧ��
void studentseek()
{
	int i;
	while(1)
	{
		cout<<"***********************************************************************"<<endl;
		cout<<"1��ѧ��  2������  3�� �绰  4���༶  5���Ա� "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"��������������Ϣ����ѧ��(�����밴0)��"<<endl;
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
			cout<<"���������Ч��"<<endl;
		}
	}

}

//��ѯ����ѧ������
void classnum()
{
	int cnum=0;						//�ֱ��¼�༶����
	string classname[30];					//��Ű༶����
	for(int i=0;i<N;i++)
	{
		if(i!=0)
		{
			bool judge=true;					//��¼�༶�Ƿ��ظ�
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
	for(int j=0;j<cnum;j++)
	{
		int num=0;
		for(int i=0;i<N;i++)
		{
			if(a[i].Class==classname[j])
				num++;
		}
		cout<<"��"<<classname[j]<<"�����ѧ������Ϊ "<<num<<endl;
	}
	pause();
}

//��ѯ��Ϣ
void Interface();						//���ܲ˵�����
void seek()
{
	if(N!=0)
	{
		int i;
		while(1)
		{
			cout<<"***********************************************************************"<<endl;
			cout<<"                   1�� ѧ����Ϣ��ѯ"<<endl;
			cout<<"                   2�� ����������ѯ"<<endl;
			cout<<"                   0�� ���ع��ܽ���"<<endl;
			cout<<"***********************************************************************"<<endl;
			cout<<"���������ѡ���ѯ��"<<endl;
			cin>>i;
			system("cls");
			switch(i)
			{
			case 1:studentseek();break;
			case 2:classnum();break;
			case 0:Interface();
			default:
				cout<<"���������Ч!"<<endl;pause();
			}
		}
	}
	else
	{
		cout<<"���κ�ѧ����Ϣ��"<<endl;
		pause();
	}
}

//ѡ��ѧ����Ϣ�޸�
void students();				//��������
void alter1()
{
	int i;
	if(N!=0)
	{
		students();
		cout<<"\n������Ҫ�޸�ѧ�������(�˳��밴0����"<<endl;
		cin>>i;
		if(i==0)
		{
			system("cls");
			Interface();
		}
		system("cls");
		if(i<=N&&i>0)
		{
			cout<<"                            ��ѧ����Ϣ"<<endl;
			cout<<a[i-1];
			a[i-1].alter();
		}
		else
		{
			cout<<"������������Ч !"<<endl;
			pause();
			alter1();
		}
	}
	else
	{
		cout<<"���κ�ѧ����Ϣ��"<<endl;
		pause();
     }
}

//ѧ��������Ϣ�޸�
void student::alter()
{
	int i;
	cout<<"***********************************************************************"<<endl;
	cout<<"           1������   2�� �Ա�  3�� �༶  4���绰  5�� ѧ�� "<<endl;
	cout<<"***********************************************************************"<<endl;
	while(1)
	{
		cout<<"���������ѡ����Ҫ�޸ĵ�ѧ����Ϣ�������밴0)��"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:cout<<"��������Ҫ�ĳɵ����֣� ";cin>>name;cout<<"�����޸����"<<endl;break;
			case 2:cout<<"��������Ҫ�ĳɵ��Ա� ";cin>>sex;cout<<"�Ա��޸����"<<endl;break;
			case 3:cout<<"��������Ҫ�ĳɵİ༶�� ";cin>>Class;cout<<"�Ա��޸����"<<endl;break;
			case 4:cout<<"��������Ҫ�ĳɵĵ绰�� ";cin>>phone;cout<<"�绰�޸����"<<endl;break;
			case 5:cout<<"��������Ҫ�ĳɵ�ѧ�ţ� ";cin>>number;cout<<"ѧ���޸����"<<endl;break;
			case 0:system("cls");alter1();
			default:
				cout<<"���������Ч��"<<endl;				
		}
	}
}

//ѧ����Ϣɾ��
void expurgate()
{
	if(N!=0)
	{
		int i;
		students();
		cout<<"��������Ҫɾ��ѧ������ţ�"<<endl;
		cin>>i;
		if(i<=N&&i>0)
		{
			for(int j=i;j<=N-1;j++)
			{
				a[j-1]=a[j];
			}
			N--;
			outinformation();
			system("cls");
			students();
			cout<<"ɾ���ɹ����밴���������"<<endl;
			getchar();
			getchar();
		}
		else
		{
			cout<<"���������Ų���ѧ��������Χ֮�ڣ�"<<endl;
			pause();
			expurgate();
		}
	}
	else
	{
		cout<<"���κ�ѧ����Ϣ��"<<endl;
		pause();
	}
}

//����ѧ�Ž�ѧ������
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
		outinformation();
		students();
		cout<<"����ɹ����밴���������"<<endl;
		getchar();getchar();
	}
	else
	{
		cout<<"���κ�ѧ����Ϣ��"<<endl;
		pause();
	
	}
}

//����ѧ����Ϣ���
void students()
{
	if(N==0)
		cout<<"��ѧ����Ϣ��"<<endl;
	else
	{
		cout<<"                            ����ѧ����Ϣ"<<endl;

		for(int j=0;j<N;j++)
		{
			cout<<a[j];
		}
	}
}

//����>>
istream &operator >>(istream &is,student &a)
{
	cout<<"����������ѧ�����������Ա𣬰༶���绰��ѧ�ţ�"<<endl;
	is>>a.name>>a.sex>>a.Class>>a.phone>>a.number; 
	cout<<"������ɣ�"<<endl;
	return is;
}
//����<<
ostream &operator <<(ostream &os,student &a)
{
	os<<"***********************************************************************"<<endl;
	os<<"ѧ�ţ� "<<a.number<<endl;
	os<<"������ "<<a.name<<endl;
	os<<"�Ա� "<<a.sex<<endl;
	os<<"�༶�� "<<a.Class<<endl;
	os<<"�绰�� "<<a.phone<<endl;
	os<<"***********************************************************************"<<endl;
	return os;
}

//���ܽ���
void Interface()
{
	int i;
	while(1)
	{
		cout<<"                  ��ӭ����ѧ����Ϣ����ϵͳ"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"                 1��  ���ѧ����Ϣ"<<endl;
		cout<<"                 2��  ��ѯѧ����Ϣ"<<endl;
		cout<<"                 3��  �޸�ѧ����Ϣ"<<endl;
		cout<<"                 4��  ɾ��ѧ����Ϣ"<<endl;
		cout<<"                 5��  ��ѧ�Ž�ѧ����Ϣ����"<<endl;
		cout<<"                 6��  �������ѧ����Ϣ"<<endl;
		cout<<"                 0��  �˳�"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"����������Ҫ��������ţ�"<<endl;
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
		case 0:exit(0);break;
		default:
			cout<<"���������Ч��"<<endl;pause();
		}
		outinformation();
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



