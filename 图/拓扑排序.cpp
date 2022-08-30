//拓扑排序
#include<iostream>
#include<string>
using namespace std;
const int MVNum=12;     //最大顶点数
struct ArcNode         //边结点
{
	int adjvex;       //邻接点的位置
	int weight;       //边的权值
	ArcNode *nextarc;
};
struct VexNode        //顶点结点
{
	string data;      //顶点数据
	ArcNode *firstarc; //指向第一条边
	bool m;
};
typedef VexNode AdList[MVNum];
struct ALGraph           //邻接表
{
	AdList vertices;
	int vexnum,arcnum;
};
struct Topo
{
	int topo[MVNum];
	int indegree[MVNum];
};
struct Stack
{
	int *base;
	int *top;
	int length;
};
int wk=0;                          
string PopVex()                   //压出顶点
{   
	if(wk>=32)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[32]=
    {"V1","V2","V1","V3","V1","V4","V1","V12","V2","V3","V3","V5","V3","V7","V3","V8","V4","V5","V5","V7","V6","V8","V9","V10",
	 "V9","V11","V9","V12","V10","V12","V11","V6"};
    return str[wk++];
}
int wn=0;
string InitVexList()         //初始化顶点表
{   if(wn>=12)
    { wn=0;cout<<"wn归零"<<endl;  }
	string str[12]={"V1","V2","V3","V4","V5","V6","V7","V8","V9","V10","V11","V12"};
	return str[wn++];
}
int LocateVex(ALGraph &G,string &v1)
{   
	for(int i=0;i<=G.vexnum;i++)
		if(i==G.vexnum)
		{ cout<<"输入错误"<<endl; cout<<"没有此点："<<v1<<" "; exit(0);  }
		else
			if(v1==G.vertices[i].data) return i;
}
void CreateDG(ALGraph &G)              //采用邻接表表示法，创建有向图G
{
	G.vexnum=12;  G.arcnum=16;         //12个顶点，16条边
	for(int i=0;i<G.vexnum;i++)
	{
		G.vertices[i].data=InitVexList();
		G.vertices[i].firstarc=NULL;
		G.vertices[i].m=false;
	}
	for(int k=0;k<G.arcnum;k++)
	{  
		string v1,v2;
		int i,j;
		v1=PopVex();  i=LocateVex(G,v1); 
		v2=PopVex();  j=LocateVex(G,v2);
		ArcNode *p=new ArcNode;
		p->adjvex=j;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
	}
}

void Output(ALGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
	{   
		ArcNode *p=G.vertices[i].firstarc;
		cout<<i+1<<"："<<G.vertices[i].data;
		while(p)
			{
				cout<<"->"<<p->adjvex+1;
				p=p->nextarc;
		}
		cout<<endl;
	}
}
void InitStack(Stack &S)
{
	S.base=S.top=new int[MVNum];
	S.length=MVNum;
}
void Push(Stack &S,int m)              //入栈
{
	if(S.top-S.base==S.length)
	{ cout<<"栈满";  exit(0);  }
	*S.top++=m;
}
int Pop(Stack &S)
{
	if(S.top==S.base)
	{ cout<<"栈空";  exit(0); }
	int m=*--S.top;
	*S.top=NULL;
	return m;
}

void FindInDegree(ALGraph &G,Topo &T)
{
	for(int i=0;i<G.vexnum;i++)
	   T.indegree[i]=0;            //初始化入度全部为0
	for(int i=0;i<G.vexnum;i++)
	{
		ArcNode *p=G.vertices[i].firstarc;   //指向顶点的第一条边
		while(p) 
			{
				T.indegree[p->adjvex]++;       //邻接点的入度加1
				p=p->nextarc;
		}
	}	
}
void TopologicalSort(ALGraph &G)
{
	 Topo T;
	 Stack S;                      //顺序栈
	 FindInDegree(G,T);
	 InitStack(S);                 //初始化栈表
	 for(int i=0;i<G.vexnum;i++)
	 if(!T.indegree[i])  Push(S,i);    //入度为0的顶点入栈
	 int m=0;  
	 int w=S.top-S.base;
	 while(w)
	 {   
		 int i;
		 i=Pop(S);
		 T.topo[m]=i;
		 m++;
		 ArcNode *p=G.vertices[i].firstarc;
		 while(p)
		 {   
			 int k=p->adjvex;
			 T.indegree[k]--;
			 if(T.indegree[k]==0)
			  Push(S,k);
			 p=p->nextarc;  
		 }
		 w=S.top-S.base;
	 }
	 if(m<G.vexnum)  cout<<"该有向图有回路"<<endl;
	for(int i=0;i<m;i++)
	 cout<<G.vertices[T.topo[i]].data<<" ";
}

int main()
{
	ALGraph G;
	CreateDG(G);
	cout<<"邻接表："<<endl;
	Output(G);
	cout<<endl;
	cout<<"该网的拓扑有序序列为："<<endl;
	TopologicalSort(G);

	system("pause");
	return 0;
}

