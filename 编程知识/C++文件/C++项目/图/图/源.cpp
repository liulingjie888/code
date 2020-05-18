#include<iostream>
using namespace std;

#define OK 0
#define ERROR -1

typedef char DataType;
typedef int Status;
//��¼��
typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode *next;
}ArcNode;
//��¼ͼ�ڵ�
typedef struct Vnode
{
	DataType data;
	ArcNode *link;

}Vnode;

class photo
{
private:
	Vnode* V;
	int len;
public:
	photo()
	{
		V=NULL;
		len=0;
	}
	//ͼ�Ĵ���
	photo(int n);
	//����ͼ
	~photo();
	
	//������ȱ���
	Status depth_Tralvel(DataType e);
	friend void depth_node_travel(photo ph,int n,int *visit);

	//������ȱ���
	Status wide_Tralvel(DataType e);
	friend void wide_node_travel(photo ph,int n,int **visit);
	int locate(DataType e);

	//�ڽӱ��ӡ
	void print();
};
//���캯��
photo::photo(int len):len(len)
{
	char add;
	ArcNode *Arc;
	ArcNode *Arc1;
	V= new Vnode[len];
	cout<<"��������������ֵ"<<endl;
	for(int j=0;j<len;j++)
	{
		cin>>V[j].data;
		V[j].link=NULL;
	}
	system("cls");
	for(int i=0;i<len;i++)
	{
		cout<<"����"<<V[i].data <<"�Ƿ�����ڽӵ㣨0����ӣ�"<<endl;
		cin>>add;
		if(add!='0'&&V[i].link==NULL)
		{
			Arc=new ArcNode;
			Arc->next=NULL;
			cout<<"�������ڽӵ��±��Ȩֵ��"<<endl;
			cin>>Arc->adjvex;
			cin>>Arc->weight;
			V[i].link=Arc;
			cout<<"�Ƿ��������ڽӵ㣨0ֹͣ��ӣ�"<<endl;
			cin>>add;
		}
		while(add!='0')
		{
			Arc1=new ArcNode;
			Arc1->next=NULL;
			cout<<"�������ڽӵ��±��Ȩֵ��"<<endl;
			cin>>Arc1->adjvex;
			cin>>Arc1->weight;

			Arc->next=Arc1;
			Arc=Arc->next;
			cout<<"�Ƿ��������ڽӵ㣨0ֹͣ��ӣ�"<<endl;
			cin>>add;
		}
		system("cls");
	}
	cout<<"�����ɹ���"<<endl;
}

//��������
photo::~photo()
{/*
	for(int i=0;i<len;i++)
	{
		ArcNode *arc1=V[i].link;
		while(arc1)
		{
			ArcNode *arc2=arc1->next;
			delete arc1;
			arc1=arc2;
		}
	}
	delete []V;
	V=NULL;
	*/
}

//���ݶ���ֵ��ȡ�±�
int photo::locate(DataType e)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(V[i].data==e)
		{
			return i;
		}
	}
	return -1;
}

//ȫͼ��ָ���ڵ�������ȱ���
Status photo::depth_Tralvel(DataType e)
{
	if(!V)
		return ERROR;
	int i;
	int *visit=new int[len];
	for(i=0;i<len;i++)
	{
		visit[i]=0;
	}
	//��ȡָ���ڵ��±�
	int flag=this->locate(e);
	//�ڵ㲻�����˳�
	if(flag==-1)
		return ERROR;
	//��ָ���ڵ㿪ʼ����
	depth_node_travel(*this,flag,visit);
	for(i=0;i<len;i++)
	{
		if(visit[i]==0)
			depth_node_travel(*this,i,visit);
	}
	cout<<endl;
	delete []visit;
	return OK;
}
//��ͼ������ȱ���
void depth_node_travel(photo ph,int n,int *visit)
{
	cout<<ph.V[n].data<<" ";
	visit[n]=1;
	ArcNode *nextarc=ph.V[n].link;
	while(nextarc)
	{
		if(visit[nextarc->adjvex]==0)
			depth_node_travel(ph,nextarc->adjvex,visit);
		nextarc=nextarc->next;
	}
}

//ȫͼ������ȱ���
Status photo::wide_Tralvel(DataType e)
{
	if(!V)
		return ERROR;
	int i;
	//��ά�����ʾ״̬��visit[0][]��ʾ�ö����Ƿ��ȡ����Χ���㣬visit[1][]�����ʾ�Ƿ������
	int **visit=new int*[2];
	for(i=0;i<2;i++)
	{
		visit[i]=new int[len];
		for(int j=0;j<len;j++)
		{
			visit[i][j]=0;
		}
	}
	//��ȡָ���ڵ��±�
	int flag=this->locate(e);
	//�ڵ㲻�����˳�
	if(flag==-1)
		return ERROR;
	//��ָ���ڵ㿪ʼ����
	wide_node_travel(*this,flag,visit);
	for(i=0;i<len;i++)
	{
		if(visit[0][i]==0)
			wide_node_travel(*this,i,visit);
	}
	cout<<endl;
	//�ͷ�
	delete []visit[1];
	delete []visit[0];
	delete []visit;
	visit=NULL;
	return OK;
}
//��ͼ������ȱ���;
void wide_node_travel(photo ph,int n,int **visit)
{
	if(visit[1][n]==0)
	{
		cout<<ph.V[n].data<<" ";
		visit[1][n]=1;
	}
	visit[0][n]=1;
	ArcNode* nextArc=ph.V[n].link;
	//���ö�����Χ�Ķ������
	while(nextArc)
	{
		if(visit[1][nextArc->adjvex]==0)		//�ж��Ƿ�������ö���
		{
			cout<<ph.V[nextArc->adjvex].data<<" ";
			visit[1][nextArc->adjvex]=1;
		}
		nextArc=nextArc->next;
	}
	nextArc=ph.V[n].link;
	while(nextArc)
	{
		if(visit[0][nextArc->adjvex]==0)		//�ж��Ƿ��������Χ����
			wide_node_travel(ph,nextArc->adjvex,visit);
		nextArc=nextArc->next;
	}
}

//��ӡ�ڽӱ�
void photo::print()
	{
		ArcNode *arc;
		for(int i=0;i<len;i++)
		{
			cout<<V[i].data<<"   ";
			arc=V[i].link;
			while(arc)
			{
				cout<<arc->adjvex<<","<<arc->weight<<"  ";
				arc=arc->next;
			}
			cout<<endl;
		}
	}

void main()
{
	
	
	DataType e;
	int i;
	int *visit=new int[5];
	for(i=0;i<5;i++)
	{
		visit[i]=0;
	}
	cout<<"���봴��ͼ�Ķ��������";
	cin>>i;
	photo ph(i);
	ph.print();
	cout<<"������ָ���ڵ㿪ʼ������ȱ���:"<<endl;
	cin>>e;
	if(ph.depth_Tralvel(e)==ERROR)
		cout<<"�����ڸ�Ԫ�ػ�Ϊ��ͼ��"<<endl;
	cout<<"������ָ���ڵ㿪ʼ������ȱ���:"<<endl;
	cin>>e;
	if(ph.wide_Tralvel(e)==ERROR)
		cout<<"�����ڸ�Ԫ�ػ�Ϊ��ͼ��"<<endl;
	system("pause");
}