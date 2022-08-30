/二叉树的复制及深度/节点数计算
#include<iostream>
using namespace std;
struct BiTreeNode
{
	char data;
	BiTreeNode *Lchild;
	BiTreeNode *Rchild;
};
typedef BiTreeNode *BiTree;


int n=-1;
char Getch()
{   n++;
	char *ch="AB#CD##E##F#GH###";
	return  *(ch+n);
}
void CreateBiTree(BiTree &T)          //DLR遍历创建二叉链表
{
	char ch;
	ch=Getch();
	if(ch=='#')  T=NULL;
	else
	{
		BiTreeNode *p=new BiTreeNode;
		p->data=ch;
		T=p;
		CreateBiTree(T->Lchild);
		CreateBiTree(T->Rchild);
	}
}

void Copy(BiTree &T,BiTree &newT)
{
	if(T==NULL)   newT=NULL;
	else
	{
		newT=new BiTreeNode;
		newT->data=T->data;
		Copy(T->Lchild,newT->Lchild);
		Copy(T->Rchild,newT->Rchild);
	}
}

int Depth(BiTree &T)
{    int n,m;
	if(T==NULL)  return 0;
	else
	{
		n=Depth(T->Lchild);
		m=Depth(T->Rchild);
		if(n>m)  return (n+1);
		else
			return (m+1);
	}
}

int NodeCount(BiTree &T)
{
	if(T==NULL)  return 0;
	else
		return NodeCount(T->Lchild)+NodeCount(T->Rchild)+1;
}

void InorderTraverse(BiTree &T)  //DLR遍历输出
{
	if(T)
	{
		cout<<T->data;
		InorderTraverse(T->Lchild);
		InorderTraverse(T->Rchild);
	}
}

int main()
{
	BiTree T,newT;
	CreateBiTree(T);
	Copy(T,newT);
	InorderTraverse(T);
	cout<<endl;
	InorderTraverse(newT);
	cout<<endl<<"Depth:"<<Depth(T);
	cout<<endl<<"NodeCount:"<<NodeCount(T);
	
	system("pause");
	return 0;
}



