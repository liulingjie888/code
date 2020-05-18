#include"linear.h"
//��ʼ�����Ա�
void LnitList(SeqList *list)
{
	list->Length=0;
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
//�������Ա�L��i��Ԫ��
DataType GetElement(SeqList *list,int i)		
{
	if(i<0||i>list->Length)
		return -1;
	else
		return list->List[i-1];
}
//����Ԫ��Ϊe��λ��
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
//�ڵ�i��λ�ò���Ԫ��e
void InsertList(SeqList *list,int i,DataType e)		
{
	for(int j=list->Length;j>=i;j++)
	{
		list->List[j]=list->List[j-1];
	}
	list->List[i-1]=e;
	list->Length++;
}
//���±�Ϊi������ֵ
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
//ɾ���±�Ϊi��Ԫ��
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
//ɾ���ظ�������Ԫ��!
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
//����
void Sort(SeqList *list)	
{
	if(ListEmpty(list))
		printf("�ձ�\n");
	else
	{
		cout<<"���� 1."<<endl;
		cout<<"���� 2."<<endl;
		DataType t;
		char i;
		i=getch();
		switch(i)
		{
		case '1':
			for(int i=0;i<list->Length-1;i++)			//ð������
				for(int j=0;j<list->Length-1-i;j++)
					if(list->List[j]>list->List[j+1])
					{
						t=list->List[j];
						list->List[j]=list->List[j+1];
						list->List[j+1]=t;
					}
			printf("����ɹ���\n");
			break;
		case '2':
			for(int i=0;i<list->Length-1;i++)		//ѡ������
				for(int j=i+1;j<list->Length;j++)
				{
					if(list->List[i]<list->List[j])
					{
						t=list->List[i];
						list->List[i]=list->List[j];
						list->List[j]=t;
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
	*p=*list;
	return p;
}
//�ϲ����Ա�!
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
//��ʾ����Ԫ��
void LookList(SeqList *list)		
{
	if(ListEmpty(list))
		printf("���Ա�Ϊ��");
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
	SeqList L,*M;
	LnitList(&L);
	
	srand((DataType)time(NULL));
	for(int i=1;i<=10;i++)
	{
		InsertList(&L,i,rand());
	}
	LookList(&L);
	M=Copy(&L);
	LookList(M);
	system("pause");
	return 0;
}