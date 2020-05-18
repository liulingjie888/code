#include<iostream>
#include<conio.h>
#include<cassert>
using namespace std;

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;


class Chain
{
private:
	Node *head;
public:
	Chain()
	{
		head=NULL;
	}
	~Chain()
	{
	}
	int getsize();						//��ȡ������
	bool insert(int pos,DataType data);	//��������
	Node* getptr(int pos);				//��ȡָ��λ�õ�Ԫ�ص�ַ
	int getplace(DataType d);			//����Ԫ��λ��
	void print();						//��ʾ����
	bool earse(int pos);				//ɾ������
	bool reverse();						//������
	void Union(Chain d);				//������������
	void destroylist();					//��������
	bool sort();						//����
	bool change(int pos,DataType data);	//��ֵ
};

//1.��ȡ������
int Chain::getsize()
{
	int n=0;
	Node *p=head;
	while(p)
	{
		p=p->next;
		n++;
	}
	return n;
}

//2.��ȡָ��λ�õ�Ԫ�ص�ַ
Node* Chain::getptr(int pos)
{
	Node *p=head;
	if(p==NULL||pos<=0||pos>getsize())
	{
		return NULL;
	}
	for(int i=1;i<pos;i++)
	{
		p=p->next;
	}
	return p;
	
}

//����Ԫ��λ��
int Chain::getplace(DataType d)
{
	if(head==NULL)
	{
		cout<<"������"<<endl;
		return 0;
	}
	int n=1;
	Node *p=head;
	while(p)
	{
		if(p->data==d)
			return n;
		p=p->next;
		n++;
	}
	if(n==getsize()+1)
	{
		cout<<"�޸����ݣ�"<<endl;
		return 0;
	}
}

//3.��������
bool Chain::insert(int pos,DataType data)
{
	if(pos>=1&&pos<=getsize()+1)		//�ж��Ƿ�Խ��
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		if(pos==1||!head)					//��������ǰ��ʱ
		{
			p->next=head;
			head=p;
			return true;
		}
		Node *q=getptr(pos-1);//��ȡǰһ��Ԫ�ص�ָ��
		Node *r=q->next;
		q->next=p;//ǰһ��Ԫ�ص�ָ���Աָ���posԪ��
		p->next=r;
		return true;
	}
	return false;
}

//4.ɾ������
bool Chain::earse(int pos)
{
	if(pos<0||pos>getsize())
		return false;
	Node *p=head;
	if(pos==1)		//ɾ����һ��Ԫ�ص����
	{
		head=(head)->next;
		free(p);
		p=NULL;
		return true;
	}
	p=getptr(pos-1);		//ָ���һԪ��
	Node *q=p->next->next;		//ָ�����Ԫ��
	free(p->next);			//ָ��ڶ�Ԫ��
	p->next=q;				//�ص㣨�ñ�һ��ֵҪͨ��ָ�����ֵ���ı䣩
	return true;
}

//5.������
bool Chain::reverse()
{
	if((!head)||(!(head)->next))
		return false;
	Node *p=head;
	Node *q=p->next;
	Node *r=q->next;
	p->next=NULL;
	q->next=p;
	while(r)
	{
		p=q;
		q=r;
		r=q->next;
		q->next=p; 
	}
	q->next=p;
	head=q;
	return true;
}

//6.������������
void Chain::Union(Chain d)
{
	if(!head)
	{
		head=d.head;
	}
	else
	{
		Node *p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=d.head;
	}
}

//7.��������
void Chain::destroylist()//����ָ���ָ��ᷢ������
{
	Node *p=head;
	while(p)
	{
		head=head->next;
		free(p);
		p=head;
	}
}

//8.����
bool Chain::sort()
{
	if(!head||!head->next)	//ð������(�Ӵ�С��
		return false;
	Node* p=head;
	DataType a;
	int n=getsize()-1;
	for(int i=1;i<=n;i++)
	{
		Node* q=p;
		for(int j=i;j<=n;j++)
		{
			if(q->data<q->next->data)
			{
				a=q->data;
				q->data=q->next->data;
				q->next->data=a;
			}
			q=q->next;
		}
	}
	/*
	while(p->next)			//ѡ������(��С����
	{
		Node* q=p->next;
		while(q)
		{
			if((p->data)>(q->data))
			{
				a=p->data;
				p->data=q->data;
				q->data=a;
			}
			q=q->next;
		}
		p=p->next;
	}*/
	return true;
}

//9.��ֵ
bool Chain::change(int pos,DataType data)
{
	if(pos<0||pos>getsize()||head==NULL)
		return false;
	Node *p=head;
	for(int i=1;i<=pos-1;i++)
	{
		p=p->next;
	}
	p->data=data;
	return true;
}

//��ʾ����
void Chain::print()
{
	if(!head)
	{
		cout<<"������"<<endl;
		return ;
	}
	Node *p=head;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	char ch;
	Chain c;
	int i;
	DataType data;
	while(1)
	{
		cout<<"0. ����Ԫ��"<<endl;
		cout<<"1. ��ȡ������"<<endl;
		cout<<"2. ����Ԫ��λ��"<<endl;
		cout<<"3. ɾ��Ԫ��"<<endl;
		cout<<"4. ������"<<endl;
		cout<<"5. ����"<<endl;
		cout<<"6. ��ֵ"<<endl;
		cout<<"7. ��ʾ����Ԫ��"<<endl;
		cout<<"8. ��������"<<endl;
		cout<<"e. �˳�����"<<endl<<endl<<endl;
		ch=getch();
		switch(ch)
		{
		case '0':
			cout<<"���� "<<c.getsize()<<endl;
			cout<<"����λ�ã�";
			cin>>i;
			cout<<"�������ݣ� ";
			cin>>data;
			if(c.insert(i,data))
				cout<<"����ɹ���"<<endl;
			else
				cout<<"����ʧ�ܣ�����λ�ò����ڣ�"<<endl;
			getch();
			system("cls");
			break;
		case'1':
			cout<<"����Ϊ"<<c.getsize ()<<endl;
			getch();
			system("cls");
			break;
		case'2':
			cout<<"�������ݣ� ";
			cin>>data;
			cout<<"λ�ã� "<<c.getplace(data)<<endl;
			getch();
			system("cls");
			break;
		case'3':
			cout<<"����Ԫ��λ�ã� "<<endl;
			cin>>i;
			if(c.earse (i))
				cout<<"ɾ���ɹ�"<<endl;
			else
				cout<<"ɾ��ʧ�ܣ�����λ�ò����ڣ�"<<endl;
			getch();
			system("cls");
			break;
		case'4':
			if(c.reverse())
				cout<<"���óɹ�!"<<endl;
			else
				cout<<"������ �� ֻ��һ��Ԫ�أ�"<<endl;
			getch();
			system("cls");
			break;
		case'5':
			if(c.sort())
				cout<<"����ɹ���"<<endl;
			else
				cout<<"������ �� ֻ��һ��Ԫ�أ�"<<endl;
			getch();
			system("cls");
			break;
		case'6':
			cout<<"���� "<<c.getsize()<<endl;
			cout<<"����λ�ã�";
			cin>>i;
			cout<<"�������ݣ� ";
			cin>>data;
			if(c.change(i,data))
				cout<<"��ֵ�ɹ���"<<endl;
			else
				cout<<"λ�ò����� �� ������"<<endl;
			getch();
			system("cls");
			break;
		case'7':
			c.print ();
			getch();
			system("cls");
			break;
		case'8':
			c.destroylist ();
			cout<<"���ٳɹ���"<<endl;
			getch();
			system("cls");
			break;
		case 'e':
			exit(0);
			break;
		default:
			system("cls");
			cout<<"���������Ч��"<<endl;
		}
	}
	system("pause");
	return 0;
}