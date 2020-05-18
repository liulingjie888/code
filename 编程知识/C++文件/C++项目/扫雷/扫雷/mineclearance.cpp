#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

#define SIZE 50 //һ��ͼƬ�Ĵ�С
#define ROW 10
#define LIST 10
#define BOMBNUM 10

int MAP[ROW+2][LIST+2];

void NumMap()
{
	srand((unsigned int)time(NULL));
	int m,n;
	for(int i=0;i<BOMBNUM;)		//����40ը������
	{
		m=rand()%ROW+1;
		n=rand()%LIST+1;
		if(MAP[m][n]!=-1)
		{
			MAP[m][n]=-1;
			i++;
		}
	}

	for(int i=1;i<=ROW;i++)		//����ÿ�����긽��ը����ֵ
	{
		for(int j=1;j<=LIST;j++)
		{
			if(MAP[i][j]==0)
			{
				int N=0;			//��¼ը����
				for(int m=i-1;m<=i+1;m++)
				{
					for(int n=j-1;n<=j+1;n++)
					{
						if(MAP[m][n]==-1)
						{
							N++;
						}
					}
				}
				MAP[i][j]=N;
			}
		}
	}
	
	for(int i=1;i<=ROW;i++)
	{
		for(int j=1;j<=LIST;j++)
		{
			printf("%2d",MAP[i][j]);
		}
		printf("\n");
	}
	
}

int main()
{
	NumMap();
	system("pause");
	return 0;
}