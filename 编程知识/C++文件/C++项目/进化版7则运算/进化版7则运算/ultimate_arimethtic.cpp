#include"stack1.h"
//�ж����ȼ�
int priority(char e)
{
	int p=0;
	switch(e)
	{
	case '-':
	case '+':p=1;break;
	case'%':
	case'/':
	case'*':p=2;break;
	case'^':p=3;
	}
	return p;
}

//��׺���ʽת��׺���ʽ
char* change(char* string)
{
	int i=0;	//���ʽ�±�
	int j=0;	//��׺�±�
	char ch;
	Stack<char> S;	//ջ
	char* suffix=new char[MAX];
	
	while(string[i]!='\0')
	{
		if(string[i]<='9' && string[i]>='0'||string[i]=='.')
		{
			suffix[j++]=string[i];
			//��һ�����ַָ���ʶ
			if((string[i+1]>'9' || string[i+1]<'0')&&string[i+1]!='.')
				suffix[j++]=C;
		}
		else
		{
			if(S.emptyStack() || string[i]=='(')
			{

				S.inputStack(string[i]);
			}
			else
			{
				if(string[i]==')')
				{
					while(S.topStack()!='(')
					{
						S.popStack(suffix[j++]);
					}
					S.popStack(ch);
				}
				else
				{
					while(priority( S.topStack())>=priority( string[i]) )
					{
						S.popStack(suffix[j++]);
					}
					S.inputStack (string[i]);
				}
			}
		}
		i++;
	}
	//ȫ����ջ
	while(!S.emptyStack())
	{
		S.popStack(suffix[j++]);
	}
	suffix[j]='\0';
	return suffix;
}

//��Ŀ����
float caculate(float a,float b,char ch)
{
	switch(ch)
	{
	case'+':return a+b;
	case'-':return a-b;
	case'*':return a*b;
	case'/':return a/b;
	case'%':return int(a)%int(b);
	case'^':return pow(a,b);
	default:
		return -1;
	}
}

//�ַ���ת����float
float transformation(char *ch,int n)
{
	int i=0;
	float sum=0;
	int flag=n;			//Ĭ��С��������������
	//��С������±�
	while(ch[i]!='\0')
	{
		if(ch[i]=='.')
		{
			flag=i;
			break;
		}
		i++;
	}
	i=0;
	while(ch[i]!='\0')
	{
		if(ch[i]!='.')
		{
			if(i<flag)	//��������
				sum=sum+(ch[i]-48)*pow(10,flag-i-1);
			else        //С������
			{
				sum=sum+(ch[i]-48)*pow(10,flag-i);
//				cout<<ch[i]-48<<"  "<<flag-i<<"  "<<pow(10,flag-i)<<endl;
			}

		}
		i++;
	}
	return sum;
}

//��������
float All_caculate(char *string)
{
	Stack<float> S_num(20);
	float num,n,m;	//��������ַ�ת������
	int i=0;
	int j;		//��������ַ����±�
	char ch[10];//��������ַ�
	while(string[i]!='\0')
	{
		//�ҳ�������ջ
		while(string[i]!='+' && string[i]!='-' && string[i]!='*' && string[i]!='/' && string[i]!='%' &&string[i]!='\0'&&string[i]!='^' )
		{
			j=0;
			while((string[i]>='0'&&string[i]<='9')|| string[i]=='.')
			{
				ch[j++]=string[i++];
			}
			ch[j]='\0';
			num=transformation(ch,j);
			
			S_num.inputStack(num);
			i++;	//�����ָ���C
		}
		//��������ջ
		while(string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i]=='/' || string[i]=='%'||string[i]=='^')
		{
				S_num.popStack(n);
				S_num.popStack(m);
				S_num.inputStack(caculate(m,n,string[i++]));
		}
	
	}
	return S_num.topStack();
}

//������
bool check(char *ch)
{
	int i=0,j,k=0;
	int n=0;	//��¼������
	char number[10];	//������ּ���
	int len=strlen(ch);
	while(ch[i]!='\0')
	{
//		cout<<"ch["<<i<<"]"<<ch[i];
		switch(ch[i])
		{
		case'(':
		case')':
			if(n>=0&&ch[i]=='(')
				n++;
			else
				n--;
		case'+':
		case'-':
		case'*':
		case'/':
		case'%':
		case'^':
		case'.':
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':i++;
			break;
		default:
			//judge=9;
			cout<<"��"<<i+1<<"���ַ�Ϊ�Ƿ��ַ���"<<endl;
			return false;
/*			//ȥ���޹��ַ�
			for(j=i;j<len-1;j++)
			{
				ch[j]=ch[j+1];
			}
			ch[len-1]='\0';
			len--;
*/
		}
	}
	//�����������Ƿ�Ϊż��
	if(n!=0)
	{
		judge=0;
		cout<<"���Ų�ƥ�䣡"<<endl;
		return false;
	}
	//�����ַ������ַ���β�ַ�
	if(!( (ch[0]>='0'&&ch[0]<='9'|| ch[0]=='(') && (ch[len-1]>='0'&&ch[len-1]<='9'  || ch[len-1]==')' ) ) )
	{
		//judge=1;
		if(!(ch[0]>='0'&&ch[0]<='9'|| ch[0]=='('))
			cout<<"���ַ�ӦΪ0-9�� ��������"<<endl;
		else
			cout<<"β�ַ�ӦΪ0-9�� ��������"<<endl;
		return false;
	}
	//�޸�bug
	else
	{
		if(ch[0]=='(')
			if( ch[1]=='+' || ch[1]=='-' || ch[1]=='*' || ch[1]== '/' || ch[1]=='%'|| ch[1]=='^' )
			{
				cout<<"����λ�� 2"<<endl;
				cout<<"�����ź��ܴ��������"<<endl;
				return false;
			}
		if(ch[len-1]==')')
			if(ch[len-2]=='+' || ch[len-2]=='-' || ch[len-2]=='*' || ch[len-2]== '/' || ch[len-2]=='%'|| ch[len-2]=='^' )
			{
				cout<<"����λ�� "<<len-1<<endl;
				cout<<"������ǰ���ܴ��������"<<endl;
				return false;
			}
	}
	for(i=1;i<len-1;i++)
	{
		bool whether=(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]== '/' || ch[i]=='%'|| ch[i]=='^');
		bool whether_follow=( ch[i+1]=='+' || ch[i+1]=='-' || ch[i+1]=='*' || ch[i+1]== '/' || ch[i+1]=='%'|| ch[i+1]=='^');
		bool whether_pioneer=( ch[i-1]=='+' || ch[i-1]=='-' || ch[i-1]=='*' || ch[i-1]== '/' || ch[i-1]=='%'|| ch[i-1]=='^' );

		if(whether)
		{
			//��������������Ƿ�����
			if(whether_follow)
			{
				//judge=2;
				cout<<"����λ�� "<<i+2<<endl;
				cout<<"����������������ڣ�"<<endl;
				return false;
			}
		}

		if(ch[i]=='(')
		{
			//����������ǰ�Ƿ�Ϊ����
			if(ch[i-1]>='0' && ch[i-1]<='9')
			{
				//judge=3;
				cout<<"����λ�� "<<i<<endl;
				cout<<"������ǰ���ܴ������֣�"<<endl;
				return false;
			}
			//���������ź��Ƿ���������
			if(whether_follow)
			{
				//judge=4;
				cout<<"����λ�� "<<i+2<<endl;
				cout<<"�����ź��ܴ��������"<<endl;
				return false;
			}
		}

		if(ch[i]==')')
		{
			//���������ź��Ƿ�Ϊ����
			if(ch[i+1]>='0'&&ch[i+1]<='9')
			{
				//judge=5;
				cout<<"����λ�� "<<i+2<<endl;
				cout<<"�����ź��ܴ������֣�"<<endl;
				return false;
			}
			//����������ǰ�Ƿ���������
			if(whether_pioneer)
			{
				//judge=6;
				cout<<"����λ�� "<<i<<endl;
				cout<<"������ǰ���ܴ����������"<<endl;
				return false;
			}
		}
		//����С������Χ�Ƿ���������ַ�
		if(ch[i]=='.')
		{
			if((ch[i-1]<'0'||ch[i-1]>'9') && (ch[i+1]<'0'||ch[i+1]>'9'))
			{
				//judge=7;
				cout<<"����λ�� "<<i+1<<endl;
				cout<<"���ܵ�������һ��С���㣡"<<endl;
				return false;
			}
		}
		//���������Ƿ����һ�����ϵ�С����
		bool whether_number=(ch[i]<='9'&&ch[i]>='0'||ch[i]=='.');
		if(whether_number)
			number[k++]=ch[i];
		else
		{
			int num=0;
			for(j=0;j<k;j++)
			{
				if(number[j]=='.')
					num++;
			}
			if(num>1)
			{
				//judge=8;
				cout<<"һ�������ڶ��С���㣡"<<endl;
				return false;
			}
			k=0;
		}
	}
	return true;
}

int main()
{
	char *ch,string[MAX];
	while(1)
	{
		cout<<"��������ʽ���˳���e����"<<endl;
		cin>>string;
		if(string[0]=='e'||string[0]=='E')
			break;
		if(check(string))
		{
			ch=change(string);
			cout<<"="<<All_caculate(ch)<<endl;
		}
		system("pause");
		system("cls");
	}
//	cout<<string<<endl;
//	cout<<transformation(string,strlen(string))<<endl;
	
	return 0;
}

/*
int main()
{
	Stack s;
	DataType data;
	char c;
	while(1)
	{
		cout<<"1.��ջ"<<endl;
		cout<<"2.��ջ"<<endl;
		cout<<"3.��ȡջ��Ԫ��"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"������ţ�"<<endl<<endl;
		cin>>c;
		switch(c)
		{
		case'1':
			cout<<"����������:"<<endl;
			cin>>data;
			if(s.inputStack(data)==0)
				cout<<"��ջ�ɹ���"<<endl;
			else
				cout<<"��ջʧ�ܣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case'2':
			if(s.popStack(data)==0)
				cout<<"��ջ�ɹ���"<<endl;
			else
				cout<<"��ջʧ�ܣ�"<<endl;
			system("pause");
			system("cls");
			break;
		case'3':
			cout<<"ջ��Ԫ��Ϊ��"<<endl;
			cout<<s.topStack()<<endl;
			system("pause");
			system("cls");
			break;
		case'0':
			exit(0);
		default:
			cout<<"������Ŵ���"<<endl;
			system("cls");
		}
	}
	return 0;
}*/