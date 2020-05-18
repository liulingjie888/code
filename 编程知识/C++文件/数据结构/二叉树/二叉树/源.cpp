#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef char DataType;

typedef struct Tree
{
	DataType data;
	struct Tree *lchild;
	struct Tree *rchild;
}Tree;
//����������
Tree* createTree(DataType Data[])
{
	Tree *T,*Ntree[MAXSIZE];
	Ntree[0]=(Tree*)malloc(sizeof(Tree));
	Ntree[0]->data=Data[0];
	Ntree[0]->lchild=NULL;
	Ntree[0]->rchild=NULL;
	T=Ntree[0];
	for(int i=1;i<MAXSIZE;i++)
	{
		if(Data[i]=='\0')
			break;
		if(Data[i]!='0')
		{
			Ntree[i]=(Tree*)malloc(sizeof(Tree));
			Ntree[i]->data=Data[i];
			Ntree[i]->lchild=NULL;
			Ntree[i]->rchild=NULL;
			int j=(i-1)/2;
			if(2*j+1==i)
				Ntree[j]->lchild=Ntree[i];
			else
				Ntree[j]->rchild=Ntree[i];
		}
	}
	return T;
}
//ǰ�����
void preorderTree1(Tree *T)
{
	if(T)
	{
		cout<<T->data<<" ";
		preorderTree1(T->lchild);
		preorderTree1(T->rchild);
	}
}
//�������
void preorderTree2(Tree *T)
{
	if(T)
	{
		preorderTree2(T->lchild);
		cout<<T->data<<" ";
		preorderTree2(T->rchild);
	}
}
//�������
void preorderTree3(Tree *T)
{
	if(T)
	{
		preorderTree3(T->lchild);
		preorderTree3(T->rchild);
		cout<<T->data<<" ";
	}
}

void main()
{
	Tree *T;
	DataType data[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
		data[i]='0';
	cout<<"���������ݴ�����������"<<endl;
	cin>>data;
	T=createTree(data);
	cout<<"ǰ�������";
	preorderTree1(T);cout<<endl;
	cout<<"���������";
	preorderTree2(T);cout<<endl;
	cout<<"���������";
	preorderTree3(T);cout<<endl;
	system("pause");
}