//链队列的实现
#include<iostream>
#include<string>
using namespace std;

struct QNode
{
	int m;
	
	QNode *next;
};
typedef QNode QueuePtr;
struct LinkQueue
{
	QueuePtr *front;
	QueuePtr *rear;
};

void InitQueue(LinkQueue &L)
{
	L.rear=L.front=new QNode;
	L.front->next=NULL;
}

void EnQueue(LinkQueue &L,int m)
{
	QNode *P=new QNode;
	P->m=m;
	P->next=NULL;
	L.rear->next=P;
	L.rear=P;
}

void  DeQueue(LinkQueue &L)
{
	if(L.rear==L.front) cout<<"ERROR";
	else
	{
		QNode *p=L.front->next;
		cout<<p->m<<" ";
		L.front->next=p->next;
		if(L.rear==p)  L.front=L.rear;
		delete p;
	}
}


int main()
{
	LinkQueue L;
	InitQueue(L);
	EnQueue(L,1);
	EnQueue(L,2);
	EnQueue(L,3);
	DeQueue(L);
	DeQueue(L);
	DeQueue(L);

	system("pause");
	return 0;
}





