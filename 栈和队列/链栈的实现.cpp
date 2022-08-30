//链栈表示和实现
#include<iostream>
using namespace std;
struct  StackNode              //设计一个栈结点空间
{
	int m;
	struct StackNode *next;
};
typedef StackNode *LinkStack;
void InitStack(LinkStack &L)    //初始化栈表   
{
	L=NULL;
}

void Push(LinkStack &L,int e)        //入栈
{
	StackNode *p=new StackNode;
	p->m=e;
	p->next=L;
	L=p;	
}

//方法一：用递归调用
void Pop(LinkStack &L)            //出栈
{
	if(L==NULL)
	{ cout<<"栈空";   exit(1);}
	else
	{
		cout<<L->m<<"  ";
		Pop(L->next);            //递归调用
	}
	
}

//方法二：常规方法
/*
void Pop(LinkStack &L)            //出栈
{
	if(L==NULL)
	{ cout<<"栈空";   exit(1);}
	while(L!=NULL)
	{
		StackNode *p=L;
		cout<<L->m;
		L=L->next;
		delete p;
	}
}
*/

int main()
{
	LinkStack L;
	InitStack(L);

	Push(L,1);
	Push(L,2);
	Push(L,3);
	Push(L,4);

	Pop(L);

	system("pause");
	return 0;
}

