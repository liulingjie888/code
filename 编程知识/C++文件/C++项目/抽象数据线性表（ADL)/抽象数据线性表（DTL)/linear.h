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

void LnitList(SeqList *list);//��ʼ�����Ա�
bool ListEmpty(SeqList *list);//�ж��Ƿ�Ϊ��
int ListLength(SeqList *list);//����Ԫ�ظ���
DataType GetElement(SeqList *list,int i);//�������Ա�L��i��Ԫ��
int LocateElement(SeqList *list,DataType e);//����Ԫ��Ϊe��λ��
void InsertList(SeqList *list,int i,DataType e);//���±�Ϊi����Ԫ��e
bool ChangeList(SeqList *list,int i,DataType e);//���±�Ϊi������ֵ
bool DeleteList(SeqList *list,int i);//ɾ���±�Ϊi��Ԫ��
void DeleteDuplicate(SeqList *list);//ɾ���ظ�������Ԫ��
void Sort(SeqList *list);//����
SeqList* Copy(SeqList *list);//�������Ա�
void MergeList(SeqList *list1,SeqList *list2);//�ϲ����Ա�
void Resolve(SeqList *list,int i);//�ֽ����Ա�
void LookList(SeqList *list);//��ʾ����Ԫ��
