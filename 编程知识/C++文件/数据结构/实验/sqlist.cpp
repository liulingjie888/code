#include<iostream.h>
#define maxsize 100
typedef int ElemType;
void creat(ElemType A[],int &n)
{
	for(int i=0;i<n;i++)
		cin>>A[i];
}
void disp(ElemType A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
}
int seach(ElemType A[],int n,ElemType item)
{
	for(int i=0;i<n;i++)
		if(A[i]==item)return i+1;
	return -1;
}
int Insert(ElemType A[],int &n,int i,ElemType item)
{
	if(i<1||i>n+1||n==maxsize)
		return -1;
	for(int j=n-1;j>=i-1;j--)
		A[j+1]=A[j];
	A[i-1]=item;
	n++;
	return 1;

}
int Delete(ElemType A[],int &n,int i)
{
	if(i<1||i>n)
		return -1;
	for(int j=i;j<n;j++)
	{
		A[j-1]=A[j];
	}
	n--;
	return 1;

}
void main()
{
	ElemType A[maxsize];
	int i;
	int n;
	ElemType item;
	while(1)
	{
		cout<<"1.创建顺序表."<<endl;
		cout<<"2.查找."<<endl;
		cout<<"3.插入元素."<<endl;
		cout<<"4.删除元素."<<endl;
		cout<<"5.输出所有元素."<<endl;

		cout<<"9.退出."<<endl;
		cout<<"please input your select:";
		cin>>i;
		switch(i)
		{
		case 1:
			cout<<"please input n:";
			cin>>n;
			creat(A,n);
			break;
		case 2:
			cout<<"please input item:";
			cin>>item;
			cout<<seach(A,n,item);
			break;
		case 3:
			cout<<"please input item and i:";
			cin>>item>>i;
			Insert(A,n,i,item);
			break;
		case 4:
			cout<<"please input i:";
			cin>>i;
			Delete(A,n,i);
			break;
		case 5:
			disp(A,n);
			break;
		case 9:
			return;
		}
	}
}


