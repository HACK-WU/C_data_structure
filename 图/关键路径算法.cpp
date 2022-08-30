//关键路径算法
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
const int MVNum=9;     //最大顶点数
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
struct Time
{
	int ve[MVNum];            //事件最早发生时间
	int vl[MVNum];            //事件最迟发生时间
};
int wk=0;                          
string PopVex()                   //压出顶点
{   
	if(wk>=22)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[22]=
    {"V0","V1","V0","V2","V0","V3","V1","V4","V2","V4","V3","V5","V4","V6","V4","V7","V5","V7","V6","V8","V7","V8"};
    return str[wk++];
}
int wn=0;
string InitVexList()         //初始化顶点表
{   if(wn>=9)
    { wn=0;cout<<"wn归零"<<endl;  }
	string str[9]={"V0","V1","V2","V3","V4","V5","V6","V7","V8"};
	return str[wn++];
}
int IW=0;
int InitWeight()
{
	if(IW>=11)
	{ IW=0; cout<<"wk归零"<<endl;  }
	int n[11]={6,4,5,1,1,2,9,7,4,2,4,};
	return n[IW++];
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
	G.vexnum=9;  G.arcnum=11;         //9个顶点，11条边
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
		p->weight=InitWeight();
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
	}
}

void Output(ALGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
	{   
		ArcNode *p=G.vertices[i].firstarc;
		cout<<i<<"："<<G.vertices[i].data;
		while(p)
			{
				cout<<"->"<<p->adjvex;
				p=p->nextarc;
		}
		cout<<endl;
	}
	cout<<"权值："<<endl;
	for(int i=0;i<G.vexnum;i++)
	{
		ArcNode *p=G.vertices[i].firstarc;
		while(p)
		{
			cout<<G.vertices[i].data<<"->"<<G.vertices[p->adjvex].data<<"："<<p->weight<<endl;
			p=p->nextarc;
		}
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
Topo T;
bool TopologicalSort(ALGraph &G)
{
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
	 if(m<G.vexnum) {  cout<<"该有向图有回路"<<endl; return false;  }
	 else
	 {
	 for(int i=0;i<m;i++)
	 cout<<G.vertices[T.topo[i]].data<<" ";
	  return true;
	 } 
}
void CriticalPath(ALGraph &G)
{
	 if(!TopologicalSort(G))  cout<<"运行失败";
	 Time Te;
	 for(int i=0;i<G.vexnum;i++)
		Te.ve[i]=0;                //初始化每件事最早发生时间为0；
  /*---------------按拓扑次序就每个事件的最早发生时间---------------*/
	 for(int i=0;i<G.vexnum;i++)
	 {
		 int k=T.topo[i];           //取得拓扑排序中顶点的序号
		 ArcNode *p=G.vertices[k].firstarc;
		 while(p)
		 {
			 int j=p->adjvex;
			 if(Te.ve[j]<Te.ve[k]+p->weight)
				 Te.ve[j]=Te.ve[k]+p->weight;
			  p=p->nextarc;
		 }
	 }
	 for(int i=0;i<G.vexnum;i++)
		 Te.vl[i]=Te.ve[G.vexnum-1];   //给每个事件的最迟发生时间初始化为ve[n-1];
	 /*-----------按逆拓扑次序求每个事件的最迟发生时间------------*/
	 for(int i=G.vexnum-1;i>=0;i--)
	 {
		 int k=T.topo[i];
		 ArcNode *p=G.vertices[k].firstarc;
		 while(p)
		 {
			 int j=p->adjvex;
			 if(Te.vl[k]>Te.vl[j]-p->weight)
				 Te.vl[k]=Te.vl[j]-p->weight;
			 p=p->nextarc;
		 }
	 }
	     cout<<endl<<endl;
		 cout<<setiosflags(ios::left);
		 cout<<setw(8)<<"顶点i"<<setw(8)<<"ve(i)"<<setw(8)<<"vl(i)"<<endl;
		 for(int i=0;i<G.vexnum;i++)
		 cout<<setw(8)<<i<<setw(8)<<Te.ve[i]<<setw(8)<<Te.vl[i]<<endl;
	 /*---------------判断每一个活动是否为关键活动-----------------*/
	 cout<<"关键路径为："<<endl;
	 for(int i=0;i<G.vexnum;i++)
	 {
		 ArcNode *p=G.vertices[i].firstarc;
		 while(p)
		 {
			 int j=p->adjvex;
			 int e=Te.ve[i];
			 int l=Te.vl[j]-p->weight;
			 if(e==l)
				 cout<<G.vertices[i].data<<"->"<<G.vertices[j].data<<" ";
			 p=p->nextarc;
		 }
	 }
}
int main()
{
	ALGraph G;
	CreateDG(G);
	cout<<"邻接表："<<endl;
	Output(G);
	cout<<endl;
	cout<<"该网的拓扑有序序列为："<<endl;
	CriticalPath(G);

	system("pause");
	return 0;
}
