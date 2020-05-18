#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MaxSize 10
typedef int DataType;

typedef struct SeqList
{
	DataType List[100];
	int Length;
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
