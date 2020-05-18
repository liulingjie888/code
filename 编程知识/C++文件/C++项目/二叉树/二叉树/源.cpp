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
//��Ҷ�ڵ�
int yeNum(Tree* T)
{
	if(!T)
		return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	return  yeNum(T->lchild)+yeNum(T->rchild);
}
//��ڵ���
int jieNum(Tree* T)
{
	if(!T)
		return 0;
	if(T)
		return jieNum(T->lchild)+jieNum(T->rchild)+1;
}
//�����
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
//���ؽڵ�ָ��
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
//���ؽڵ����ڲ��
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
	cout<<"���������ݴ�����������"<<endl;
	cin>>data;
	T=createTree(data);
	cout<<"ǰ�������";
	preorderTree1(T);cout<<endl;
	cout<<"���������";
	preorderTree2(T);cout<<endl;
	cout<<"���������";
	preorderTree3(T);cout<<endl;
	cout<<"�ڵ���Ϊ"<<jieNum(T)<<endl;
	cout<<"Ҷ�ڵ���Ϊ"<<yeNum(T)<<endl;
	cout<<"���Ϊ��"<<depth(T)<<endl;
	char ch;
	cout<<"������Ҫ���ҵ����ݣ�";
	cin>>ch;
	cout<<"��Ԫ�����Ϊ"<<reaDepth(T,ch,1)<<endl;
	system("pause");
}