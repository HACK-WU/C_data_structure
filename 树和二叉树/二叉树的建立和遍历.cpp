//二叉树的建立和遍历
#include<iostream>
using namespace std;

const int MAXSIZE=10;
struct BiTreeNode      //树节点
{
	char data;
	BiTreeNode *Lchild;
	BiTreeNode *Rchild;
};
typedef BiTreeNode *BiTree;
struct Stack            //栈空间
{    
	BiTreeNode* top;
	BiTreeNode* base;
	int length;
};

void InitStack(Stack &S)
{
	S.base=S.top=new BiTreeNode[MAXSIZE];
	if(!S.base) 
	{  cout<<"内存申请失败";   exit(0); }
	S.length=MAXSIZE;
}

int whole_n=-1;           //定义一个全局变量；
char* Getch( )
{   whole_n++;
char *ch="AB#CD##E##F#GH###";
	return ch+whole_n;
}            
void CreateBiTree(BiTree &T)        //先序遍历建立二叉链表
{
	char *ch=Getch();
	cout<<*ch;
	if(*ch=='#') T=NULL;
	else
	{
		BiTreeNode *p=new BiTreeNode;
		p->data=*ch;
		T=p;;
		CreateBiTree(T->Lchild); 
		CreateBiTree(T->Rchild);
	}
}

void InOrderTraverse_DG(BiTree &T)         //递归算法中序遍历二叉树链表
{
	if(T)
	{
		InOrderTraverse_DG(T->Lchild);
		cout<<T->data;
		InOrderTraverse_DG(T->Rchild);
	}
}

void PushStack(Stack &S,BiTreeNode* &p)
{
	if(S.top-S.base==S.length)
		cout<<"栈满";
	else
	{
		S.top=p;
	    S.top++;
	}
}

void PopStack(Stack &S,BiTreeNode* &q)
{   
	if(S.top==S.base)
		cout<<"栈空";
	else
	{     S.top--;	     
			q=S.top;
			S.top=NULL;
	}
}

void InorderTraverse(BiTree &T,Stack &S)     //非递归算法中序遍历二叉链表     
{
	BiTreeNode *p=T;
	BiTreeNode* q=new BiTreeNode;                  
	while(p||S.base)
	{  
		if(p)
		{   
			PushStack(S,p);			
			p=p->Lchild;
		}
		else
		{   
			PopStack(S,q);
			cout<<q->data;	   //bug
			p=q->Rchild;
		}		
	}
}
					
int main()
{
	Stack S;
	BiTree T;
	InitStack(S);
	CreateBiTree(T);
	cout<<endl<<"输出字符（递归算法）：";
	InOrderTraverse_DG(T);
	cout<<endl<<"输出字符（非递归算法）：";
	InorderTraverse(T,S);
	system("pause");
	return 0;
}
