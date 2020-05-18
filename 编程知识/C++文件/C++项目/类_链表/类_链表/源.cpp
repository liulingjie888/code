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
	int getsize();						//获取链表长度
	bool insert(int pos,DataType data);	//插入链表
	Node* getptr(int pos);				//获取指定位置的元素地址
	void print();						//显示数据
	bool earse(int pos);				//删除链表
	void reverse();						//链表倒置
	void Union(Chain d);				//两个链表连接
	void destroylist();					//销毁链表
	bool sort();						//排序
	bool change(int pos,DataType data);	//换值
};
//获取链表长度
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
//插入链表
bool Chain::insert(int pos,DataType data)
{
	if(pos>=1&&pos<=getsize()+1)		//判断是否越界
	{
		Node *p=(Node*)malloc(sizeof(Node));
		p->data=data;
		p->next=NULL;
		if(pos==1)					//插入在最前面时
		{
			p->next=this->head;
			this->head=p;
			return true;
		}
		if(!this->head)
			if(pos==getsize()+1)		//插入在最后面
			{
				Node *q=this->head;
				while(q->next)
				{
					q=q->next;
				}
				q->next=p;
				return true;
			}
		Node *q=getptr(pos-1);//获取前一个元素的指针
		Node *r=q->next;
		q->next=p;//前一个元素的指针成员指向第pos元素
		p->next=r;
		return true;
	}
}
//获取指定位置的元素地址
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
//显示数据
void Chain::print()
{
	if(!this->head)
	{
		printf("空链表！\n");
		return ;
	}
	Node *p=this->head;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}
//删除链表
bool Chain::earse(int pos)
{
	if(pos<0||pos>getsize())
		return false;
	Node *p=this->head;
	if(pos==1)		//删除第一个元素的情况
	{
		this->head=this->head->next;
		free(p);
		p=NULL;
		return true;
	}
	p=getptr(pos-1);		//指向第一元素
	Node *q=p->next->next;		//指向第三元素
	free(p->next);			//指向第二元素
	p->next=q;				//重点（该边一个值要通过指向这个值来改变）
	return true;
}
//链表倒置
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
//两个链表连接
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
//销毁链表
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
//排序
bool Chain::sort()
{
	if(!this->head||!this->head->next)	//冒泡排序法(从大到小）
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
	while(p->next)			//选择排序法(从小到大）
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
//换值
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