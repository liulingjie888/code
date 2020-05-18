#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct tagStudent
{
	char Name[20];
	int Age;
	int StuNum;
	int Score;
}Student;			//typedef������Ľṹ�������

typedef struct tagNode
{
	Student stu;		//ѧ����Ϣ
	struct tagNode* pNext;  //ָ����һ���ڵ��ָ��
}Node;

Node* g_pHead=NULL;		//����ͷ�ڵ�(����β�ڵ�һ����NULL)

//����
//��һ�ڳ���
//�ڵ�

void InputStudent();		//����ѧ����Ϣ
void PrintStudent();		//��ӡѧ���ɼ�

int main()
{
	while(1)
	{
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Чѧ���ɼ�����ϵͳv1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\tѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");

	char ch=getch();
	switch(ch)
	{
	case'1':
		InputStudent();
		break;
	case'2':
		PrintStudent();
		break;
	case'3':
		break;
	case'4':
		break;
	case'5':
		break;
	case'6':
		break;
	case'7':
		break;
	case'8':
		break;
	case'0':
		printf("��ӭ�ٴ�ʹ�ã��ټ���");
		
		system("pause");
		return 0;
		break;
	}
	}
	char ch=getch();
	system("pause");
	return 0;
}

void InputStudent()
{
	printf("������ѧ����Ϣ������ ѧ�� ���� �ɼ���\n");
	//�����ҵ������β�ڵ�
	Node* p=g_pHead;  //��ǰ�ڵ�
	while(p!=NULL&&p->pNext!=NULL)	//��ȡβ�ڵ�p.pNext
	{
		p=p->pNext;
	}
	//����һ���½ڵ㣬void*����ָ��
	Node* pNewNode=(Node*)malloc(sizeof(Node));
	//��β�ڵ㸳ֵ��NULL
	pNewNode->pNext=NULL;
	//���ڵ���뵽����β������Ϊ����ͷ�ڵ�
	if(g_pHead==NULL)
	{
		g_pHead=pNewNode;
	}
	else
	{
		p->pNext=pNewNode;
	}
	scanf("%s",pNewNode->stu.Name);
	scanf("%d",&pNewNode->stu.StuNum);
	scanf("%d",&pNewNode->stu.Age);
	scanf("%d",&pNewNode->stu.Score);
	printf("ѧ����Ϣ���¼��ɹ���\n");
	system("pause");
	system("cls");
}

void PrintStudent()
{
	Node* p;
	p=g_pHead;
	system("cls");
	while(p!=NULL)
	{
		printf("������%s\tѧ�ţ�%d\t���䣺%d\t�ɼ���%d\n",p->stu.Name,p->stu.StuNum,p->stu.Age,p->stu.Score);
		p=p->pNext;
	}
	system("pause");
}
