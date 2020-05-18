#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

#define SIZE 10
#define OK 0
#define ERROR -1

typedef int Status;
typedef int DataType;

typedef struct SeqList
{
	DataType *qList;
	int Length;
	int Maxsize;
}SeqList;

void LnitList(SeqList *list);//��ʼ�����Ա�
bool ListEmpty(SeqList *list);//�ж��Ƿ�Ϊ��
int ListLength(SeqList *list);//����Ԫ�ظ���
DataType GetElement(SeqList *list,int i);//�������Ա�L��i��Ԫ��
Status LocateElement(SeqList *list,DataType e);//����Ԫ��Ϊe��λ��
Status InsertList(SeqList *list,int i,DataType e);//���±�Ϊi����Ԫ��e
Status ChangeList(SeqList *list,int i,DataType e);//���±�Ϊi������ֵ
Status DeleteList(SeqList *list,int i);//ɾ���±�Ϊi��Ԫ��
void DeleteRepetion(SeqList *list);//ɾ���ظ�������Ԫ��
void Sort(SeqList *list);//����
SeqList* Copy(SeqList *list);//�������Ա�
void MergeList(SeqList *list1,SeqList *list2);//�ϲ����Ա�
void Resolve(SeqList *list,int i);//�ֽ����Ա�
void LookList(SeqList *list);//��ʾ����Ԫ��

//��ʼ�����Ա�
void LnitList(SeqList *list)
{
	list->Length=0;
	list->qList=(DataType*)malloc(SIZE*sizeof(DataType));
	if(!list->qList)
	{
		printf("��ʼ��ʧ�ܣ������ڴ�ʧ�ܣ�");
		return ;
	}
	list->Maxsize=SIZE;
}
//�ж��Ƿ�Ϊ��
bool ListEmpty(SeqList *list)		
{
	return list->Length==0;
}
//����Ԫ�ظ���
int ListLength(SeqList *list)		
{
	return list->Length;
}
//�鿴���Ա�L��i��Ԫ��
DataType GetElement(SeqList *list,int i)		
{
	if(i<0||i>list->Length)
	{
		printf("λ�ó�����Χ �� ������Ϊ�գ�\n");
		return ERROR;
	}
	else
		printf("��λ��Ԫ��Ϊ %d\n",list->qList[i-1]);
		return OK;
}
//����Ԫ��Ϊe��λ��
Status LocateElement(SeqList *list,DataType e)		
{
	if(ListEmpty(list))
	{
		printf("������");
		return ERROR;
	}
	bool b=true;
	int i;
	for(i=0;i<list->Length;i++)
	{
		if(list->qList[i]==e)
		{
			printf("��Ԫ��λ��Ϊ %d\n",i+1);
			b=false;
		}
	}
	if(b)
		printf("��Ԫ�ز����ڣ�\n");
	return OK;
}
//�ڵ�i��λ�ò���Ԫ��e
Status InsertList(SeqList *list,int i,DataType e)		
{
	if(i<=0||i>list->Length+1)
	{
		printf("λ�ó�����Χ�������");
		return ERROR;
	}
	if(list->Length>=list->Maxsize)
	{
		DataType *p=(DataType*)realloc(list->qList,(list->Maxsize+SIZE)*sizeof(DataType));
		if(!p)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			return ERROR;
		}
		list->qList=p;
		list->Maxsize+=SIZE;
	}
	for(int j=list->Length;j>=i;j--)
	{
		list->qList[j]=list->qList[j-1];
	}
	list->qList[i-1]=e;
	list->Length++;
	return OK;
}
//���±�Ϊi������ֵ
Status ChangeList(SeqList *list,int i,DataType e)		
{
	if(i<0||i>list->Length)
	{
		printf("λ�ó�����Χ�������");
		return ERROR;
	}
	else
	{
		list->qList[i-1]=e;
		return OK;
	}
}
//ɾ���±�Ϊi��Ԫ��
Status DeleteList(SeqList *list,int i)		
{
	if(i<0||i>list->Length)
	{
		printf("λ�ó�����Χ�������");
		return ERROR;
	}
	else
	{
		for(int j=i;j<=list->Length-1;j++)
		{
			list->qList[j-1]=list->qList[j];
		}
		list->Length--;
		return OK;
	}
}
//ɾ���ظ�������Ԫ��!
void DeleteRepetiion(SeqList *list)	
{
	if(ListEmpty(list))
	{
		printf("������");
		return ;
	}
	int i=0,j;
	while(i<list->Length)
	{
		j=i+1;
		while(j<list->Length)
		{
			if(list->qList[i]==list->qList[j])
				DeleteList(list,j+1);
			else
				j++;
		}
		i++;
	}
	printf("��ɾ���ظ�Ԫ�أ�");
}
//����
void Sort(SeqList *list)	
{
	if(ListEmpty(list))
		printf("�ձ�\n");
	else
	{
		printf("����  1.\n");
		printf("����  2.\n");
		DataType t;
		char i;
		i=getch();
		switch(i)
		{
		case '1':
			for(int i=0;i<list->Length-1;i++)			//ð������
				for(int j=0;j<list->Length-1-i;j++)
					if(list->qList[j]>list->qList[j+1])
					{
						t=list->qList[j];
						list->qList[j]=list->qList[j+1];
						list->qList[j+1]=t;
					}
			printf("����ɹ���\n");
			break;
		case '2':
			for(int i=0;i<list->Length-1;i++)		//ѡ������
				for(int j=i+1;j<list->Length;j++)
				{
					if(list->qList[i]<list->qList[j])
					{
						t=list->qList[i];
						list->qList[i]=list->qList[j];
						list->qList[j]=t;
					}
				}
			printf("����ɹ���\n");
			break;
		default:
			printf("��������");
		}
	}
}
//�������Ա�
SeqList* Copy(SeqList *list)
{
	SeqList *p=(SeqList*)malloc(sizeof(SeqList));
	if(!p)
	{
		printf("SeqList�����ڴ�ʧ�ܣ�\n");
		return NULL;
	}
	p->qList=(DataType*)malloc(list->Maxsize*sizeof(DataType));
	if(!p->qList)
	{
		printf("SeqList->qList�����ڴ�ʧ�ܣ�\n");
		return NULL;
	}
	p->Maxsize=list->Maxsize;
	for(int i=0;i<list->Length;i++)
	{
		p->qList[i]=list->qList[i];
	}
	p->Length=list->Length;
	return p;
}
//�ϲ����Ա�!
void MergeList(SeqList *list1,SeqList *list2)		
{
	if(list1->Length+list2->Length>list1->Maxsize)
	{
		DataType *p=(DataType*)realloc(list1->qList,(list1->Length+list2->Length+SIZE)*sizeof(DataType));
		if(!p)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			return ;
		}
		list1->qList=p;
		list1->Maxsize=list1->Length+list2->Length+SIZE;
	}
	for(int i=0;i<list2->Length;i++)
		list1->qList[i+list1->Length]=list2->qList[i];
	list1->Length=list1->Length+list2->Length;
}
//��ʾ����Ԫ��
void LookList(SeqList *list)		
{
	if(ListEmpty(list))
	{
		printf("���Ա�Ϊ��!\n");
		return ;
	}
	for(int i=0;i<list->Length;i++)
		printf("%d  ",list->qList[i]);
	printf("\n");
}
//˳������
Status Input(SeqList *list,DataType data)
{
	if(list->Length>=list->Maxsize)
	{
		DataType *p=(DataType*)realloc(list->qList,(list->Maxsize+SIZE)*sizeof(DataType));
		if(!p)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			return ERROR;
		}
		list->qList=p;
		list->Maxsize+=SIZE;
	}
	list->qList[list->Length]=data;
	list->Length++;
	printf("����ɹ���\n");
}

int main()
{
	SeqList s;
	LnitList(&s);
	char ch;
	int i;
	DataType data;
	while(1)
	{
		printf("i. ˳����������\n");
		printf("1. ��ȡ˳������\n");
		printf("2. �鿴ָ��λ��Ԫ��\n");
		printf("3. ����ָ��Ԫ��λ��\n");
		printf("4. ָ��λ�ò���Ԫ��\n");
		printf("5. ָ��λ�����¸�ֵ\n");
		printf("6. ɾ��ָ��λ��Ԫ��\n");
		printf("7. ɾ��˳����ظ�Ԫ��\n");
		printf("8. ����\n");
		printf("9. ��ӡ���Ա�\n");
		printf("0. �˳�����\n\n");
		ch=getch();
		switch(ch)
		{
		case'i':
			printf("���������ݣ�\n");
			scanf("%d",&data);
			Input(&s,data);
			getch();
			system("cls");
			break;
		case'1':
			printf("˳������Ϊ %d\n",ListLength(&s));
			getch();
			system("cls");
			break;
		case'2':
			printf("������λ�ã�");
			scanf("%d",&i);
			GetElement(&s,i);
			getch();
			system("cls");
			break;
		case'3':
			printf("���������ݣ�");
			scanf("%d",&data);
			LocateElement(&s,data);
			getch();
			system("cls");
			break;
		case'4':
			printf("����λ�ã�");
			scanf("%d",&i);
			printf("�������ݣ�");
			scanf("%d",&data);
			if(InsertList(&s,i,data)==OK)
				printf("����ɹ���\n");
			else
				printf("����ʧ�ܣ�\n");
			getch();
			system("cls");
			break;
		case'5':
			printf("����λ�ã�");
			scanf("%d",&i);
			printf("�������ݣ�");
			scanf("%d",&data);
			if(ChangeList(&s,i,data)==OK)
				printf("��ֵ�ɹ���\n");
			else
				printf("��ֵʧ�ܣ�\n");
			getch();
			system("cls");
			break;
		case'6':
			printf("����λ�ã�");
			scanf("%d",&i);
			if(DeleteList(&s,i)==OK)
				printf("ɾ���ɹ���\n");
			else
				printf("ɾ��ʧ�ܣ�\n");
			getch();
			system("cls");
			break;
		case'7':
			DeleteRepetiion(&s);
			getch();
			system("cls");
			break;
		case'8':
			Sort(&s);
			getch();
			system("cls");
			break;
		case'9':
			LookList(&s);
			getch();
			system("cls");
			break;
		case'0':
			exit(0);
		default:
			printf("���������Ч�����������룡");
			system("cls");
		}
	}
	system("pause");
	return 0;
}