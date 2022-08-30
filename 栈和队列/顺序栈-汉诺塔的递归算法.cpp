///顺序栈—汉诺塔递归算法
#include<iostream>
using namespace std;
struct Stack;               //结构体的申明
void Push_2(Stack &A,int n);//函数的申明
void Move(Stack &A,int n,Stack &B);
const int MAXSIZE=100;
struct Stack
{
	int *top;
	int *base;
	int stacksize;
};

void InitStack(Stack &A)                 //初始化栈
{
	A.base=new int[MAXSIZE];
	if(!A.base)
	{ cout<<"创建失败！";  exit(1);  }
	A.top=A.base;
	A.stacksize=MAXSIZE;
}

int Push(Stack &A)           //入栈
{
	int n;
	if(A.top-A.base==A.stacksize)
	{ cout<<"栈满"<<" ";  exit(1);  }
	else
		{
			cout<<"汉诺塔圆盘的个数：";  cin>>n;
	Push_2(A,n);                //调用递归函数
	}
	return n;
}
void Push_2(Stack &A,int n)           //用递归调用实现入栈
{
	if(n==1) *A.top++=1;
	if(n>1)
	{
		*A.top++=n;
		Push_2(A,n-1);
	}
}

void Push_3(Stack &A,int n)
{
	*A.top++=n;
}

void Pop(Stack &A,int n)
{  
	if(A.top-n==A.base)
	cout<<"栈空"<<" "; 
	else
	{   n++;
		cout<<*(A.top-n)<<" ";
		Pop(A,n);                  //调用递归函数
	}
}

void Hanoi(Stack &A,Stack &B,Stack &C,int n)
{   
    if(n==1) Move(A,1,C);
	else
	{   
		Hanoi(A,C,B,n-1);   
		Move(A,n,C);       
		Hanoi(B,A,C,n-1);  
	}
}	 

void  Move(Stack &A,int n,Stack &C)
{
	Push_3(C,*(A.top-(n-(n-1))));       //入栈
	A.top--;
	
}

int main()
{   int n;
	Stack A;
	Stack B;
	Stack C;
    InitStack(A);
	InitStack(B);
	InitStack(C);
    n=Push(A);
	cout<<"出状态A："<<endl;
	Pop(A,0);
    cout<<endl<<"运算中请稍等...";
	Hanoi(A,B,C,n);
	cout<<endl;
	cout<<"C："; Pop(C,0);
	cout<<endl<<"运算完成";

	system("pause");
	return 0;
}
