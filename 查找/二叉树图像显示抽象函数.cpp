/*---------------------二叉树图像显示函数---------------------*/
#include<iomanip>
#include<string>
const int MAXSIZE=20;
typedef BSTree ElemType;
typedef BSTreeNode TypeNode;
struct Qdata
{
	int m;
	int predistance;
	TypeNode *p_BI;         //指向二叉树结点的地址
};
struct SQueue                  //顺序队列
{
	Qdata data[MAXSIZE];
	int front,rear;           //队列指针
};
struct Data
{
	int m;
	int predistance;
	string str;
};
struct SQueue_str
{
	Data data[MAXSIZE];
	int front,rear;
};
void InitQueue(SQueue &q,SQueue_str &q_str)      //队列初始化
{
	q.front=q.rear=0;
	q.data[q.front].m=NULL;
	q.data[q.front].p_BI=NULL;
	q.data[q.front].predistance=0;

	q_str.front=q_str.rear=0;
	q_str.data[q_str.front].m=NULL;	
	q_str.data[q_str.front].predistance=0;
}
void EnQueue(SQueue &q,ElemType &T,int n,int pre)   //入队
{
	if((q.rear+1)%MAXSIZE==q.front)  
	{   cout<<"队满";   exit(0);  }
	q.data[q.rear].p_BI=T;
	q.data[q.rear].m=n;
	q.data[q.rear].predistance=pre;
	q.rear=(q.rear+1)%MAXSIZE;
}
void EnQueue_str(SQueue_str &q_str,string str,int n,int pre)
{
	if(q_str.rear+1==q_str.front) 
	{  cout<<"队满";   exit(0);  }
	q_str.data[q_str.rear].str=str;
	q_str.data[q_str.rear].m=n;
	q_str.data[q_str.rear].predistance=pre;
	q_str.rear++;
}
Qdata* DeQueue(SQueue &q)               //出队
{
	if(q.front==q.rear)
	{  cout<<"队空";   exit(0);  }
	Qdata *m=q.data+q.front;            //将data中第front的地址赋给m
	q.front=(q.front+1)%MAXSIZE;
	return m;
}
Data* DeQueue_str(SQueue_str &q_str)
{
	if(q_str.front==q_str.rear)
	{  cout<<"队空";  exit(0);  }
	return q_str.data+q_str.front++;
}
int DepPath(ElemType &T)               //计算二叉树的深度
{
	int n,m;
	if(!T) return 0;
	else
	{   
		n=DepPath(T->Lchild);
		m=DepPath(T->Rchild);
		if(n>=m) return(n+1);
		else
			return(m+1);
	}
}
 void Output_pictureBT(ElemType &T)         //显示二叉树的图形
 {                  
	int deep=DepPath(T);
	int n=(((deep*4)/2)/4+1)*4;          //树根的位置
    SQueue q;
	SQueue_str q_str;
	InitQueue(q,q_str);
	string Lstr="/";
	string Rstr="\\";
    EnQueue(q,T,n,0);                   //入队
    int m=q.rear-q.front;             //m=0;队空；
	int m_str=q_str.rear-q_str.front;
	while(m||m_str)
	{  
	   int PreDistance=0;            //记录同一层顶点直接前驱的坐标位置
	   int PreDistance_str=0;        //记录同一层符号直接前驱的坐标位置
	while(m)
	{
		Qdata *p=DeQueue(q);
		int k=p->m;                 //宽度
		cout<<setw(k-p->predistance)<<p->p_BI->key;
		if(p->p_BI->Lchild)
		{   
		    EnQueue_str(q_str,Lstr,k-1,PreDistance_str);
			PreDistance_str=k-1;
            EnQueue(q,p->p_BI->Lchild,k-2,PreDistance);
			PreDistance=k-2;
		}
	   if(p->p_BI->Rchild)
	   {
			EnQueue_str(q_str,Rstr,k+1,PreDistance_str);
		    PreDistance_str=k+1;
			EnQueue(q,p->p_BI->Rchild,k+2,PreDistance);
			PreDistance=k+2;		
		}
		 m--; 
	}

	cout<<endl;
	m_str=q_str.rear-q_str.front;
	while(m_str)
	{  
        Data *p_str=DeQueue_str(q_str);
		int k_str=p_str->m;
		cout<<setw(k_str-p_str->predistance)<<p_str->str;
		m_str--;
	}
	cout<<endl;
	 m=q.rear-q.front;             //m=0;队空；
	 m_str=q_str.rear-q_str.front;
	}
}
/*--------------------二叉树图像显示函数编写完毕--------------*/

int main()
{
	Elemtype T;
	//图像输出
	cout<<endl;
	cout<<"二叉树图像为："<<endl;
	Output_pictureBT(T);

	system("pause");
	return 0;
}
	