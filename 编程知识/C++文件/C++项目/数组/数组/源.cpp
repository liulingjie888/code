#include <iostream>
#include<time.h>
using namespace std;

#define OK 0
#define ERROR -1
#define MAX 30

typedef int Staus;
typedef int DataType;
//矩阵元素结构体
typedef struct
{
	int i;
	int j;
	DataType data;

}triple;
 //矩阵结构体
typedef struct
{
	int mu,nu,tu;	//行数，列数，非零个数
	triple Data[MAX];

}tsmatrix;
//矩阵转置
tsmatrix* transposesmatrix(tsmatrix *M)
{
	if(M->tu)
	{
		tsmatrix *N=(tsmatrix*)malloc(sizeof(tsmatrix));
		for(int p=0;p<M->tu;p++)
		{
			N->Data[p].i=M->Data[p].j;
			N->Data[p].j=M->Data[p].i;
			N->Data[p].data=M->Data[p].data;
		}
		N->nu=M->mu;
		N->mu=M->nu;
		N->tu=M->tu;
		return N;
	}
	return M;
}
//打印矩阵
void print(tsmatrix *M)
{
	for(int p=1;p<=M->mu;p++)
	{
		for(int q=1;q<=M->nu;q++)
		{
			int flag=0;
			for(int n=0;n<M->tu;n++)
			{
				if(M->Data[n].i==p&&M->Data[n].j==q)
				{
					cout.width(6);
					cout<<M->Data[n].data;
					flag=1;
				}
			}
			if(flag==0)
			{
				cout.width(6);
				cout<<0;
			}

		}
		cout<<endl;
	}

}
//矩阵初始化
Staus lnit(tsmatrix *M,int i,int j,int k)
{
	if(i>0&&j>0&&k>0&&k<=i*j)
	{
		M->mu=i;
		M->nu=j;
		M->tu=k;
		srand((unsigned)time(NULL));
		for(int p=0;p<M->tu;p++)
		{

			M->Data[p].data=rand();
			while(1)
			{
				int flag=0;
				M->Data[p].i=rand()%i+1;
				M->Data[p].j=rand()%j+1;
				for(int q=0;q<p;q++)
				{
					if(M->Data[q].i==M->Data[p].i&&M->Data[q].j==M->Data[p].j)
						flag=1;
				}
				if(flag==0)
					break;
			}
			cout<<M->Data[p].j<<"  "<<M->Data[p].i<<"  "<<M->Data[p].data<<endl;
		}
		return OK;
	}
	return ERROR;
}

void main()
{
	tsmatrix t;
	lnit(&t,3,4,8);
	cout<<endl<<endl;
	print(&t);
	cout<<endl<<endl;
	tsmatrix *q=transposesmatrix(&t);
	print(q);
	system("pause");
}