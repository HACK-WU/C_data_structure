//括号的匹配“()”，“[]”.
#include<iostream>
using namespace std;
const int MAXSIZE=3;
struct SqStack
{
	char *base;
	char *top;
	int length;
};

void InitStack(SqStack &L)
{
	L.base=L.top=new char[MAXSIZE];
	L.length=MAXSIZE;
}

void Push(SqStack &L,char ch)
{
	if(L.top-L.base==L.length)
		cout<<"栈满";
	else
		*L.top++=ch;
}

void Pop(SqStack &L)
{
	if(L.top==L.base)
		cout<<"栈空";
	else
		cout<<*(--L.top);
}

void Matching(SqStack &L)
{
	InitStack(L);
	int flag=1;
	char ch;
	cout<<"请输入字符：";
	cin>>ch;
	while(ch!='#'&&flag)
	{
		switch(ch)
		{
		case '[':
		case '(':  Push(L,ch);  break;
		case ')':
			if(L.top!=L.base&&*(L.top-1)=='(')
			{  Pop(L);cout<<')';cout<<endl; }
			else flag=0;  
			break;
		case ']':
			if(L.top!=L.base&&*(L.top-1)=='[')
			{ Pop(L);cout<<']';cout<<endl; }
			else flag=0;
			break;
		}
		cout<<"请输入字符：";
		cin>>ch;
	}
	if(L.base==L.top&&flag) 
		cout<<"匹配成功";
	else 
		cout<<"匹配失败";
}

int main()
{
	SqStack L;
	Matching(L);
	
	 system("pause");
	 return 0;
}

