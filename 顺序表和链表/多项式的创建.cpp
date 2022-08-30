#include<iostream>
#include<math.h>
using namespace std;

struct Space
{
	float coef;           //系数
	int espn;             //指数
	struct Space *next;
	struct Space *prior;
};
typedef Space *Head_p;

void Create_head_p(Head_p &L)  //创建头结点
{
	L=new Space;
	L->coef=NULL;
	L->espn=NULL;
	L->next=NULL;
}
void CreateList(Head_p &L)       //录入
{
	cout<<"请将多项式“P(x)=10+4x^5+8x^7+5x^10+7x^3+2x”"
		<<"的各项输入到下列程序中"
		<<endl<<endl;
	Space *p;
	p=L;
	while(p->next)
	{
		p=p->next;
	}
int i;
for(i=0;i<6;i++)
{
	Space *s=new Space;
	cout<<"第"<<i+1<<"项："<<endl
		<<"系数：";
	cin>>s->coef;
	cout<<"  "<<"指数：";
	cin>>s->espn;

	Space *pre=p;                
	Space *q=p->next;
	while(q&&q->espn<s->espn)
	{
		pre=q;
		q=q->next;
	}
	s->next=q;
	pre->next=s;
}
}

void Output(Head_p &L)
{
	Space *p=L->next;
	cout<<"P(X)=";
	while(p)
	{
		if(p->coef<0)
		cout<<"-"<<p->coef<<"X^"<<p->espn;
		if(p->espn<0)
		{
			if(p!=L->next)
				cout<<"+";
			cout<<p->coef<<"X^"<<"-"<<p->espn;
		}
		if(p->coef<0&&p->espn<0)
	       cout<<"-"<<p->coef<<"X^"<<"-"<<p->espn;
		if(p!=L->next)
				cout<<"+";
		cout<<p->coef<<"X^"<<p->espn;
		p=p->next;
	}
}

int main()
{  
	Head_p L;
	Create_head_p(L);
	CreateList(L);
	Output(L);

	system("pause");
	return 0;
}
