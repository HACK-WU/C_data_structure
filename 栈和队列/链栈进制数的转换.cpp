//链栈进制数的转换
#include<iostream>
using namespace std;

struct StackNode
{
	int m;
	StackNode *next;
};

typedef StackNode *LinkStack;

void InitStack(LinkStack &S)
{
	S=NULL;
}

void Push(LinkStack &S,int n)
{
	StackNode *p=new StackNode;
	p->m=n;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S)
{
	while(S!=NULL)
	{
		cout<<S->m;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
}

void consersion(LinkStack &S)  //进制转换
{
	int n,m;
	cout<<"请输入要初始值：";cin>>n;
	cout<<"要转换成几进制数？：";cin>>m;
	while(n)
	{
		Push(S,n%m);
		n=n/m;
	}
	if(n<0)
		cout<<"错误，n应该大于0;";
	else
		Pop(S);
}

int main()
{
	LinkStack S;
	InitStack(S);
    consersion(S);

	system("pause");
	return 0;
}

