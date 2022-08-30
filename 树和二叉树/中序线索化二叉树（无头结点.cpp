//中序线索化二叉树（无头结点）
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
void InitPre(BiThrTree &T)              //初始化pre指针
{   
	pre=T;
	
}
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

int main()
{
	BiThrTree T;
	CreateBiTree(T);
	InitPre(T);            //初始化全局变量pre
	InThreading(T);        //线索化
	InorderTraverse(T);     //遍历

    system("pause");
	return 0;
}

		


	
