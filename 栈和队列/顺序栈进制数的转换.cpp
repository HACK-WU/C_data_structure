//顺序栈进制数的转换
#include<iostream>
using namespace std;

const int MAXSIZE=20;
struct SqStack
{
	int *base;
	int *top;
	int  length;	
};

void InitStack(SqStack &L)
{
	L.base=L.top=new int[MAXSIZE];
	if(!L.base) {cout<<"内存分配失败"; exit(1); }
	L.length=MAXSIZE;
}

void PushStack(SqStack &L,int n)
{
	if(L.top-L.base==L.length) 
	cout<<"栈满！";
	else
		*L.top++=n;
}

void PopStack(SqStack &L)
{
	while(L.base!=L.top)
	{   cout<<*(--L.top);   }
}

void consersion(SqStack &L)  //进制转换
{
	int n,m;
	cout<<"请输入要初始值：";cin>>n;
	cout<<"要转换成几进制数？：";cin>>m;
	while(n)
	{
		PushStack(L,n%m);
		n=n/m;
	}
	if(n<0)
		cout<<"错误，n应该大于0;";
	else
		PopStack(L);
}

int main()
{
	SqStack L;
	InitStack(L);
	consersion(L);
	
	system("pause");
	return 0;
}



