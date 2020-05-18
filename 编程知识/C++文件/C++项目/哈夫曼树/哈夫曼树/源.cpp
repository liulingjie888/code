#include<iostream>
using namespace std;
#define MAX 30

typedef int DataType;

typedef struct Tree
{
	DataType data;
	struct Tree *rchild;
	struct Tree *lchild;
}Tree;

void sort(DataType *huffman,int len)
{
	DataType t;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			if(huffman[j]>huffman[j+1])
			{
				t=huffman[j];
				huffman[j]=huffman[j+1];
				huffman[j+1]=t;
			}
		}
	}
}
//前序遍历
void qian_list(Tree* T)
{
	if(T)
	{
		cout<<T->data<<" ";
		qian_list(T->lchild);
		qian_list(T->rchild);
	}
}
//创建哈夫曼树
Tree* createHuftree(DataType *huffman,int len)
{
	sort(huffman,len);

	Tree **T=(Tree**)malloc(len*sizeof(Tree*));
	for(int i=0;i<len;i++)
	{
		T[i]=(Tree*)malloc(sizeof(Tree));
		T[i]->data=huffman[i];
		T[i]->lchild=NULL;
		T[i]->rchild=NULL;
	}

	int j;
	int dex=0;
	Tree *new_ptr;

	while(1)
	{
		
		new_ptr=(Tree*)malloc(1*sizeof(Tree));
		new_ptr->data=T[dex]->data+T[dex+1]->data;
		new_ptr->lchild=T[dex];
		new_ptr->rchild=T[dex+1];
		T[dex]=NULL;
		T[dex+1]=NULL;
		j=dex+2;
		dex++;
        if(dex==len-1)
        {
            break;
        }
        while(new_ptr->data>T[j]->data)
        {
            T[j-1]=T[j];
            j++;
            if(j==len)
             break;
        }
        T[j-1]=new_ptr;
    }
	return new_ptr;
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
//编码
void interpret(Tree* T,int len)
{
	static int code[MAX];
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		cout<<T->data<<"  ";
		for(int i=0;i<len;i++)
		{
			cout<<code[i];
		}
		cout<<endl;
	}
	else
	{
		code[len]=0;
		interpret(T->lchild,len+1);
		code[len]=1;
		interpret(T->rchild,len+1);
	}
}

int main()
{
	int len;
	DataType *huffman;
	Tree *T;
	cout<<"请输入权值个数:"<<endl;
	cin>>len;
	huffman=new DataType [len];
	cout<<"请输入如权值:"<<endl;
	for(int i=0;i<len;i++)
	{
		cin>>huffman[i];
	}
	T=createHuftree(huffman,len);
	cout<<"前序遍历："<<endl;
	qian_list(T);
	cout<<endl;
	cout<<"解码："<<endl;
	interpret(T,0);
	cout<<"叶节点数："<<yeNum(T)<<endl;
	cout<<"节点数："<<jieNum(T)<<endl;
	system("pause");
	return 0;
}