//循环顺序队列的实现
#include<iostream>
using namespace std;
const int MAXSIZE=10;

struct SqQueue
{
	int *base;
	int front;
	int rear;
};

void InitQueue(SqQueue &L)
{
	L.base=new int[MAXSIZE];
	if(!L.base)  
	{ cout<<"创建失败。"; exit(1); }
	L.front=L.rear=0;
}

void EnQueue(SqQueue &L,int n)
{
	if(n>0)
	if((L.rear+1)%MAXSIZE==L.front)
	        cout<<"队满"; 
	else
		{  
			L.base[L.rear]=n;
			L.rear=(L.rear+1)%MAXSIZE;
			EnQueue(L,n-1);
	}
	else
		cout<<"已录入";
}

void DeQueue(SqQueue &L)
{
	if(L.rear==L.front)
		cout<<"对空";
	else
	{
		cout<<L.front<<" ";
		L.front=(L.front+1)%MAXSIZE;
		DeQueue(L);
	}
}

int main()
{
	int n;
	SqQueue L;
	InitQueue(L);
	cout<<"Input n：";cin>>n;
	cout<<endl;
	EnQueue(L,n);
	DeQueue(L);

	system("pause");
	return 0;
}