#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int DataType;

typedef struct SeqList
{
	DataType *qList;
	int Length;
	int Maxsize;
}SeqList;

void LnitList(SeqList *list);//初始化线性表
bool ListEmpty(SeqList *list);//判断是否为空
int ListLength(SeqList *list);//返回元素个数
DataType GetElement(SeqList *list,int i);//返回线性表L第i个元素
int LocateElement(SeqList *list,DataType e);//返回元素为e的位置
void InsertList(SeqList *list,int i,DataType e);//在下标为i插入元素e
bool ChangeList(SeqList *list,int i,DataType e);//在下标为i存入新值
bool DeleteList(SeqList *list,int i);//删除下标为i的元素
void DeleteDuplicate(SeqList *list);//删除重复的数据元素
void Sort(SeqList *list);//排序
SeqList* Copy(SeqList *list);//复制线性表
void MergeList(SeqList *list1,SeqList *list2);//合并线性表
void Resolve(SeqList *list,int i);//分解线性表
void LookList(SeqList *list);//显示所有元素

//初始化线性表
void LnitList(SeqList *list)
{
	list->Length=0;
	list->qList=(DataType)malloc(
}
//判断是否为空
bool ListEmpty(SeqList *list)		
{
	return list->Length==0;
}
//返回元素个数
int ListLength(SeqList *list)		
{
	return list->Length;
}
//返回线性表L第i个元素
DataType GetElement(SeqList *list,int i)		
{
	if(i<0||i>list->Length)
		return -1;
	else
		return list->List[i-1];
}
//返回元素为e的位置
int LocateElement(SeqList *list,DataType e)		
{
	if(ListEmpty(list))
		return -1;
	else
		for(int i=0;i<list->Length;i++)
		{
			if(list->List[i]==e)
				return i+1;
		}
		return 0;
}
//在第i个位置插入元素e
void InsertList(SeqList *list,int i,DataType e)		
{
	for(int j=list->Length;j>=i;j++)
	{
		list->List[j]=list->List[j-1];
	}
	list->List[i-1]=e;
	list->Length++;
}
//在下标为i存入新值
bool ChangeList(SeqList *list,int i,DataType e)		
{
	if(i<0||i>list->Length)
	{
		return false;
	}
	else
	{
		list->List[i-1]=e;
		return true;
	}
}
//删除下标为i的元素
bool DeleteList(SeqList *list,int i)		
{
	if(i<0||i>list->Length)
		return false;
	else
	{
		for(int j=i;j<=list->Length-1;j++)
		{
			list->List[j-1]=list->List[j];
		}
		list->Length--;
		return true;
	}
}
//删除重复的数据元素!
void DeleteDuplicate(SeqList *list)	
{
	int i=0,j;
	while(i<list->Length)
	{
		j=i+1;
		while(j<list->Length)
		{
			if(list->List[i]==list->List[j])
				DeleteList(list,j+1);
			else
				j++;
		}
		i++;
	}
}
//排序
void Sort(SeqList *list)	
{
	if(ListEmpty(list))
		printf("空表！\n");
	else
	{
		cout<<"升序： 1."<<endl;
		cout<<"降序： 2."<<endl;
		DataType t;
		char i;
		i=getch();
		switch(i)
		{
		case '1':
			for(int i=0;i<list->Length-1;i++)			//冒泡排序
				for(int j=0;j<list->Length-1-i;j++)
					if(list->List[j]>list->List[j+1])
					{
						t=list->List[j];
						list->List[j]=list->List[j+1];
						list->List[j+1]=t;
					}
			printf("升序成功！\n");
			break;
		case '2':
			for(int i=0;i<list->Length-1;i++)		//选择排序
				for(int j=i+1;j<list->Length;j++)
				{
					if(list->List[i]<list->List[j])
					{
						t=list->List[i];
						list->List[i]=list->List[j];
						list->List[j]=t;
					}
				}
			printf("降序成功！\n");
			break;
		default:
			printf("输入有误！");
		}
	}
}
//复制线性表
SeqList* Copy(SeqList *list)
{
	SeqList *p=(SeqList*)malloc(sizeof(SeqList));
	*p=*list;
	return p;
}
//合并线性表!
void MergeList(SeqList *list1,SeqList *list2)		
{
	if(list1->Length+list2->Length>MaxSize)
		return ;
	else
	{
		for(int i=list1->Length;i<list1->Length+list2->Length;i++)
			list1->List[i]=list2->List[i-list1->Length];
		list1->Length=list1->Length+list2->Length;
		cout<<list1->Length<<endl;
	}

}
//显示所有元素
void LookList(SeqList *list)		
{
	if(ListEmpty(list))
		printf("线性表为空");
	else
	{
		for(int i=0;i<list->Length;i++)
		{
			cout<<list->List[i]<<"  ";
		}
		cout<<endl;
	}
}

int main()
{
	char ch;
	cout<<"0. 插入元素"<<endl;
	cout<<"1. 获取链表长度"<<endl;
	cout<<"2. 查找元素位置"<<endl;
	cout<<"3. 删除元素"<<endl;
	cout<<"4. 链表倒置"<<endl;
	cout<<"5. 排序"<<endl;
	cout<<"6. 换值"<<endl;
	cout<<"7. 显示所有元素"<<endl;
	cout<<"8. 销毁链表"<<endl;
	cout<<"e. 退出程序"<<endl<<endl<<endl;
	ch=getch();
	switch(ch)
	{

	default:

	}
	system("pause");
	return 0;
}