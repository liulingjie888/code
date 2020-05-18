#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct tagStudent
{
	char Name[20];
	int Age;
	int StuNum;
	int Score;
}Student;			//typedef给定义的结构体起别名

typedef struct tagNode
{
	Student stu;		//学生信息
	struct tagNode* pNext;  //指向下一个节点的指针
}Node;

Node* g_pHead=NULL;		//链表头节点(链表尾节点一定是NULL)

//链表
//做一节车箱
//节点

void InputStudent();		//输入学生信息
void PrintStudent();		//打印学生成绩

int main()
{
	while(1)
	{
	printf("*************************************************\n");
	printf("*\t欢迎使用高效学生成绩管理系统v1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
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
		printf("欢迎再次使用，再见！");
		
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
	printf("请输入学生信息：姓名 学号 年龄 成绩：\n");
	//首先找到链表的尾节点
	Node* p=g_pHead;  //当前节点
	while(p!=NULL&&p->pNext!=NULL)	//获取尾节点p.pNext
	{
		p=p->pNext;
	}
	//创建一个新节点，void*泛型指针
	Node* pNewNode=(Node*)malloc(sizeof(Node));
	//将尾节点赋值成NULL
	pNewNode->pNext=NULL;
	//将节点插入到链表尾部或做为链表头节点
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
	printf("学生信息添加录入成功！\n");
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
		printf("姓名：%s\t学号：%d\t年龄：%d\t成绩：%d\n",p->stu.Name,p->stu.StuNum,p->stu.Age,p->stu.Score);
		p=p->pNext;
	}
	system("pause");
}
