/*双链有序表的合并*/
#include<iostream>
#include<string>
using namespace std;

struct Space
{
    int m;
    struct Space *next;
    struct Space *prior;
};
typedef Space *LinkList;

void L_Space(LinkList &L)//创建一个头节点函数
{
    L=new Space;
    L->m=NULL;
    L->next=NULL;
    L->prior=NULL;
}

void Input(LinkList &L,int m)//录入数据
{
    Space *p;
    p=L;
    while(p->next)
    {
		p=p->next;
	}

	Space *s;
	s=new Space;
	s->m=m;
	s->next=NULL;
	p->next=s;
	s->prior=p;
}

void Output(LinkList &L,string &LA)//输出数据
{
    Space *p;
    p=L->next;
    cout<<LA<<"："<<" ";
	while(p)
	{
		cout<<p->m<<"  ";
		p=p->next;
	}
    
    cout<<endl;
}

void MergeList(LinkList &LA,LinkList &LB,LinkList &LC)
{
    LC=LA;
    Space *pa=LA->next;
	Space *pb=LB->next;
    Space *pc=LC;
    while(pa&&pb)
    {
        if(pa->m<=pb->m)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
	delete LB;
}

int main()
{
    LinkList LA;   //创建一个Space类型的指针变量
    LinkList LB;
    LinkList LC;

    L_Space(LA);   //创建头节点
    L_Space(LB);

    Input(LA,3);  //录入LA表格
    Input(LA,5);
    Input(LA,8);
    Input(LA,11);

    Input(LB,2);  //录入LB表格
    Input(LB,6);
    Input(LB,8);
    Input(LB,9);
    Input(LB,11);
    Input(LB,15);
    Input(LB,20);

	string La=("LA");
	string Lb=("LB");
	string Lc=("LC");
    Output(LA,La);   //显示LA表格
    Output(LB,Lb);   //显示LB表格

    MergeList(LA,LB,LC);  //LA和LB的合并
    Output(LC,Lc);

    system("pause");
    return 0;
}


