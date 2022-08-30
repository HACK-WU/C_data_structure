//链栈—汉诺塔的递归算法 
#include<iostream>
using namespace std;

struct  StackNode              //设计一个栈结点空间
{
	int m;
	struct StackNode *next;
	struct StackNode *prior;
};
typedef StackNode *LinkStack;
void InitStack(LinkStack &L)    //初始化栈表   
{
	L=new StackNode;
	L->m=NULL;
	L->next=NULL;
	L->prior=NULL;
}

void Push(LinkStack &L,int e)        //入栈
{   
	if(e==0)  cout<<"入栈完成"<<endl;
	else
	{
	StackNode *p=new StackNode;
	L->m=e;
	L->prior=p;
	p->next=L;
	L=p;
	Push(L,e-1);
	}
}

void Pop(LinkStack &L)            //出栈
{   
	if(L->next==NULL)
	{ 
		cout<<"栈空";  
   }
	else
	{
		cout<<L->next->m<<"  ";
		L=L->next;
		Pop(L);            //递归调用
	}
}

void Push1(LinkStack &C,int n)
{
	StackNode *p=new StackNode;
	C->m=n;
	C->prior=p;
	p->next=C;
	C=p;
}
void Move(LinkStack &A,LinkStack &C)
{
	Push1(C,A->m);
	StackNode *p;
	p=A;
	A=A->next;cout<<A->m;
	delete p;
}

void Hanoi(LinkStack &A,LinkStack &B,LinkStack &C)
{  
	if(A->m==1) Move(A,C);           //如果A上只有一个圆盘，将其移到C上；
	else
	{ 
	    A=A->prior;                 //A向上移一个空间
		Hanoi(A,C,B);                   //将A包括A以上的圆盘移到B上
		Move(A,C);  
		Hanoi(B,A,C);
	}
}

int main()
{   
	LinkStack A;
	LinkStack B;
	LinkStack C;
	InitStack(A);
	InitStack(B);
	InitStack(C);
	int n;
	cout<<"请输入圆盘的个数：";cin>>n;
	Push(A,n);
	cout<<"A：";
	Pop(A);
	cout<<endl
		;

    Hanoi(A,B,C);
	cout<<"C：";
	Pop(C);
	system("pause");
	return 0;
}
