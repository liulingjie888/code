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
//创建二叉树
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
//前序遍历
void preorderTree1(Tree *T)
{
	if(T)
	{
		cout<<T->data<<" ";
		preorderTree1(T->lchild);
		preorderTree1(T->rchild);
	}
}
//中序遍历
void preorderTree2(Tree *T)
{
	if(T)
	{
		preorderTree2(T->lchild);
		cout<<T->data<<" ";
		preorderTree2(T->rchild);
	}
}
//后序遍历
void preorderTree3(Tree *T)
{
	if(T)
	{
		preorderTree3(T->lchild);
		preorderTree3(T->rchild);
		cout<<T->data<<" ";
	}
}
//求叶节点
int yeNum(Tree* T)
{
	if(!T)
		return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	return  yeNum(T->lchild)+yeNum(T->rchild);
}
//求节点数
int jieNum(Tree* T)
{
	if(!T)
		return 0;
	if(T)
		return jieNum(T->lchild)+jieNum(T->rchild)+1;
}
//求深度
int depth(Tree* T)
{
//	static int dep=0;
	if(!T)
		return 0;
	int right=depth(T->lchild );
	int left=depth(T->rchild );
	if(left>right)
		return left+1;
	else
		return right+1;
}
//返回节点指针
Tree* node(Tree *T,DataType e)
{
	Tree* pr;
	if(T->data==NULL)
		return NULL;
	else
	{
		if(T->data==e)
			return T;
		else
		{
			if(pr=node(T->lchild,e))
				return pr;
			else if(pr=node(T->rchild,e))
				return pr;
			return NULL;
		}
	}
}
//返回节点所在层次
int reaDepth(Tree *T,DataType e,int len)
{
	int depth;
	if(!T)
		return 0;
	else
		if(T->data==e)
			return len;
		else
		{
			if((depth=reaDepth(T->lchild,e,len+1))!=0)
				return depth;
			if((depth=reaDepth(T->rchild,e,len+1))!=0)
				return depth;
			return 0;
		}
}
void main()
{
	Tree *T;
	DataType data[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
		data[i]='0';
	cout<<"请输入数据创建二叉树："<<endl;
	cin>>data;
	T=createTree(data);
	cout<<"前序遍历：";
	preorderTree1(T);cout<<endl;
	cout<<"中序遍历：";
	preorderTree2(T);cout<<endl;
	cout<<"后序遍历：";
	preorderTree3(T);cout<<endl;
	cout<<"节点数为"<<jieNum(T)<<endl;
	cout<<"叶节点数为"<<yeNum(T)<<endl;
	cout<<"深度为："<<depth(T)<<endl;
	char ch;
	cout<<"输入你要查找的数据：";
	cin>>ch;
	cout<<"该元素深度为"<<reaDepth(T,ch,1)<<endl;
	system("pause");
}