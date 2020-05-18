#include<iostream>
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
	~Chain();
	int getsize();						//��ȡ������
	bool insert(int pos,DataType data);	//��������
	Node* getptr(int pos);				//��ȡָ��λ�õ�Ԫ�ص�ַ
	void print();						//��ʾ����
	bool earse(int pos);				//ɾ������
	void reverse();						//������
	void Union(Chain d);				//������������
	void destroylist();					//��������
	bool sort();						//����
	bool change(int pos,DataType data);	//��ֵ
};
//��ȡ������
int Chain::getsize()
{
	int n=0;
	while(this->head)
	{
		this->head=this->head->next;
		n++;
	}
	return n;
}
//��������
bool Chain::insert(int pos,DataType data)
{
	if(pos>=1&&pos<=getsize()+1)		//�ж��Ƿ�Խ��
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		if(pos==1)					//��������ǰ��ʱ
		{
			p->next=this->head;
			this->head=p;
			return true;
		}
		if(!this->head)
			if(pos==getsize()+1)		//�����������
			{
				Node *q=this->head;
				while(q->next)
				{
					q=q->next;
				}
				q->next=p;
				return true;
			}
		Node *q=getptr(pos-1);//��ȡǰһ��Ԫ�ص�ָ��
		Node *r=q->next;
		q->next=p;//ǰһ��Ԫ�ص�ָ���Աָ���posԪ��
		p->next=r;
		return true;
	}
}
//��ȡָ��λ�õ�Ԫ�ص�ַ
Node* Chain::getptr(int pos)
{
	Node *p=this->head;
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
//��ʾ����
void Chain::print()
{
	if(!this->head)
	{
		printf("������\n");
		return ;
	}
	Node *p=this->head;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}
//ɾ������
bool Chain::earse(int pos)
{
	if(pos<0||pos>getsize())
		return false;
	Node *p=this->head;
	if(pos==1)		//ɾ����һ��Ԫ�ص����
	{
		this->head=this->head->next;
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
//������
void Chain::reverse()
{
	if((!this->head)||(!(this->head)->next))
		return ;
	Node *p=this->head;
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
	this->head=q;
}
//������������
void Chain::Union(Chain d)
{
	if(!this->head)
	{
		this->head=d.head;
	}
	else
	{
		Node *p=this->head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=d.head;
	}
}
//��������
Chain::~Chain()
{
	Node *p=this->head;
	while(p)
	{
		this->head=(this->head)->next;
		free(p);
		p=this->head;
	}
	this->head=NULL;
}
//����
bool Chain::sort()
{
	if(!this->head||!this->head->next)	//ð������(�Ӵ�С��
		return false;
	Node* p=this->head;
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
//��ֵ
bool Chain::change(int pos,DataType data)
{
	if(pos<0||pos>getsize()||head==NULL)
		return false;
	Node *p=this->head;
	for(int i=1;i<=pos-1;i++)
	{
		p=p->next;
	}
	p->data=data;
	return true;
}

int main()
{
	Chain h;
	h.insert(0,34);
	cout<<h.getsize()<<endl;

	h.print ();
	system("pause");
	return 0;
}