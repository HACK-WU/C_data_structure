//中序线索化二叉树(带头结点）
#include<iostream>
using namespace std;
struct BiThrNode
{
	char data;
	BiThrNode *Lchild;
	BiThrNode *Rchild;                                                                
	int LTag,RTag;
};
typedef BiThrNode *BiThrTree;

int whole_n=-1;
char Getch()
{
	whole_n++;
	char *ch="ABKY###CD##E##F#GH###";
	return *(ch+whole_n);
}
void CreateBiTree(BiThrTree &T)         //DLR创建二叉树链表
{
	char ch;
	ch=Getch();
	if(ch=='#') T=NULL;
	else
	{
		BiThrNode *p=new BiThrNode;
		p->data=ch;
		T=p;
		CreateBiTree(T->Lchild);
		CreateBiTree(T->Rchild);
	}
}

BiThrNode *pre;
void InThreading(BiThrTree &T)         //线索化二叉链表
{	
	if(T)
	{  
		InThreading(T->Lchild);
		if(!T->Lchild)
		{
		   T->LTag=1;
		   T->Lchild=pre;		 
	    }
		else
			T->LTag=0;
		if(!pre->Rchild)
		{
			pre->RTag=1;
            pre->Rchild=T;
		}
		else
			pre->RTag=0;
		pre=T;
		InThreading(T->Rchild);
	}
}

void InorderThreading(BiThrTree &Thrt,BiThrTree &T)
{
	Thrt=new BiThrNode;
	Thrt->LTag=0;
	Thrt->LTag=1;
	Thrt->Rchild=Thrt;
	if(!T)  Thrt->Lchild=Thrt;
	else
	{
		Thrt->Lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->Rchild=Thrt;
		pre->RTag=1;
		Thrt->Rchild=pre;
	}
}

void InorderTraverse(BiThrTree &T)
{
	if(T)
	{
		cout<<T->data;
		if(T->LTag!=1)
		InorderTraverse(T->Lchild);
		if(T->RTag!=1)
		InorderTraverse(T->Rchild);
	}
}

void InorderTraverse_Thrt(BiThrTree &Thrt)
{
	BiThrNode *p=Thrt->Lchild;
	while(p!=Thrt)
	{
		while(p->LTag==0)  p=p->Lchild;
		cout<<p->data;
		while(p->RTag==1&&p->Rchild!=Thrt)
		{ 
			p=p->Rchild;  cout<<p->data;
		}
		p=p->Rchild;
	}
}


int main()
{  
	BiThrTree T,Thrt;
	CreateBiTree(T);	
	InorderThreading(Thrt,T);
	InorderTraverse(T);          //递归遍历
	cout<<endl;
	InorderTraverse_Thrt(Thrt);  //非递归遍历

    system("pause");
	return 0;
}
