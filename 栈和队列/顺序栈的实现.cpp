//顺序栈表示和实现
#include<iostream>
using namespace std;
const int MAXSIZE=100;
struct  Stack               //设计一个栈空间
{
	int *top;
	int *base;
	int stacksize;
};

void InitStack(Stack &L)    //初始化栈表   
{
	L.base=new int[MAXSIZE];
	if(!L.base)
	{
		cout<<"创建失败";
	exit(1);                 //正常退出
	}
	L.top=L.base;
	L.stacksize=MAXSIZE;
}

void Push(Stack &L,int e)        //入栈
{
	if(L.top-L.base==L.stacksize) //判断是否栈满
	{
		cout<<"栈满";   exit(1);  
	}
		*L.top++=e;               //将e元素压入栈顶，栈顶指针加一
	
}

void Pop(Stack &L)            //出栈
{
	while(L.top!=L.base)
	{
		cout<<*--L.top;        //栈顶指针减一，然后输出指向的元素
	}
}

int main()
{
	Stack L;
	InitStack(L);

	Push(L,1);
	Push(L,2);
	Push(L,3);
	Push(L,4);

	Pop(L);

	system("pause");
	return 0;
}

