#include"stack.h"
//判断优先级
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
	}
	return p;
}

//中缀表达式转后缀表达式
char* change(char* string)
{
	int i=0;	//表达式下标
	int j=0;	//后缀下标
	char ch;
	Stack<char> S;	//栈
	char* suffix=new char[MAX];
	
	while(string[i]!='\0')
	{
		if(string[i]<='9' && string[i]>='0')
		{
			suffix[j++]=string[i];
			//将一组数字分隔标识
			if(string[i+1]>'9' || string[i+1]<'0')
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
	//全部出栈
	while(!S.emptyStack())
	{
		S.popStack(suffix[j++]);
	}
	suffix[j]='\0';
	return suffix;
}

//二目计算
float caculate(float a,float b,char ch)
{
	switch(ch)
	{
	case'+':return a+b;
	case'-':return a-b;
	case'*':return a*b;
	case'/':return a/b;
	case'%':return int(a)%int(b);
	default:
		return -1;
	}
}

//字符数转化成float
float transformation(char *ch,int n)
{
	int i=0;
	float sum=0;
	int flag=n;	//默认小数点在整数后面
	//求小数点的下标
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
			if(i<flag)	//整数部分
				sum=sum+(ch[i]-48)*pow(10,flag-i-1);
			else        //小数部分
			{
				sum=sum+(ch[i]-48)*pow(10,flag-i);
//				cout<<ch[i]-48<<"  "<<flag-i<<"  "<<pow(10,flag-i)<<endl;
			}

		}
		i++;
	}
	return sum;
}

//四则运算
float All_caculate(char *string)
{
	Stack<float> S_num(20);
	float num,n,m;	//存放数字字符转化的数
	int i=0;
	int j;		//存放数字字符的下标
	char ch[10];//存放数字字符
	while(string[i]!='\0')
	{
		//找出数字入栈
		while(string[i]!='+' && string[i]!='-' && string[i]!='*' && string[i]!='/' && string[i]!='%' )
		{
			j=0;
			while(string[i]>='0'&&string[i]<='9')
			{
				ch[j++]=string[i++];
			}
			ch[j]='\0';
			num=transformation(ch,j);
			S_num.inputStack(num);
			i++;
		}
		//计算结果入栈
		while(string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i]=='/' || string[i]=='%')
		{
				S_num.popStack(n);
				S_num.popStack(m);
				S_num.inputStack(caculate(m,n,string[i++]));
		}
	
	}
	return S_num.topStack();
}

//检查语句
bool check(char *ch)
{
	int i=0,j;
	int n=0;	//记录括号数
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
				n--;cout<<n<<endl;
		case'+':
		case'-':
		case'*':
		case'/':
		case'%':
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
			//去除无关字符
			for(j=i;j<len-1;j++)
			{
				ch[j]=ch[j+1];
			}
			ch[len-1]='\0';
			len--;
		}
	}
	//检验括号数是否为偶数
	if(n!=0)
		return false;
	//检验字符串首字符和尾字符
	if(!( (ch[0]>='0'&&ch[0]<='9'|| ch[0]=='(') && (ch[len-1]>='0'&&ch[len-1]<='9'  || ch[len-1]==')' ) ) )
		return false;
	for(i=2;i<len-1;i++)
	{
		bool whether=(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]== '/' || ch[i]=='%');
		bool whether_follow=( ch[i+1]=='+' || ch[i+1]=='-' || ch[i+1]=='*' || ch[i+1]== '/' || ch[i+1]=='%');
		bool whether_pioneer=( ch[i-1]=='+' || ch[i-1]=='-' || ch[i-1]=='*' || ch[i-1]== '/' || ch[i-1]=='%' );

		if(whether)
			//检验两个运算符是否相邻
			if(whether_follow)
				return false;

		if(ch[i]=='(')
		{
			//检验左括号前是否为数字
			if(ch[i-1]>='0' && ch[i-1]<='9')
				return false;
			//检验左括号后是否存在运算符
			if(whether_follow)
				return false;
		}

		if(ch[i]==')')
		{
			//检验右括号后是否为数字
			if(ch[i+1]>='0'&&ch[i+1]<='9')
				return false;
			//检验右括号前是否存在运算符
			if(whether_pioneer)
				return false;
		}
	}
	return true;
}

int main()
{
	char *ch,string[MAX];
	cout<<"请输入表达式："<<endl;
	cin>>string;
	if(check(string))
	{
		ch=change(string);
		cout<<"="<<All_caculate(ch)<<endl;
	}
	else
		cout<<"输入有误！"<<endl;
	
	
//	cout<<string<<endl;
//	cout<<transformation(string,strlen(string))<<endl;
	
	system("pause");
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
		cout<<"1.入栈"<<endl;
		cout<<"2.出栈"<<endl;
		cout<<"3.获取栈顶元素"<<endl;
		cout<<"0.退出"<<endl;
		cout<<"输入序号："<<endl<<endl;
		cin>>c;
		switch(c)
		{
		case'1':
			cout<<"请输入数据:"<<endl;
			cin>>data;
			if(s.inputStack(data)==0)
				cout<<"入栈成功！"<<endl;
			else
				cout<<"入栈失败！"<<endl;
			system("pause");
			system("cls");
			break;
		case'2':
			if(s.popStack(data)==0)
				cout<<"出栈成功！"<<endl;
			else
				cout<<"出栈失败！"<<endl;
			system("pause");
			system("cls");
			break;
		case'3':
			cout<<"栈顶元素为："<<endl;
			cout<<s.topStack()<<endl;
			system("pause");
			system("cls");
			break;
		case'0':
			exit(0);
		default:
			cout<<"输入序号错误！"<<endl;
			system("cls");
		}
	}
	return 0;
}*/