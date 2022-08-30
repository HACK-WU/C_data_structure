//图—BFS遍历邻接表
#include<iostream>
#include<string>
using namespace std;
const int MVNum=20;
struct ArcNode         //边结点
{
	int adjvex;       //邻接点的位置
	int weight;       //边的权值
	ArcNode *nextarc;
};
struct SQueue
{
	int *que;
	int front,rear;
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

void InitQueue(SQueue &Q)
{  
	Q.que=new int[10];
	Q.front=Q.rear=0;
}

void EnQueue(SQueue &Q,int m)        //入队
{
	if((Q.rear+1)%10==Q.front)
	{  cout<<"队满"; exit(0);  }
	Q.que[Q.rear]=m;
	Q.rear=(Q.rear+1)%10;
}
int DeQueue(SQueue &Q)                   //出队
{   Q.front=Q.front%10;
	if(Q.front==Q.rear)
	{ cout<"队空";  exit(0);  }
	return Q.que[Q.front++];
}

int wk=0;                          
string PopVex()                   //压出顶点
{   
	if(wk>=22)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[22]=
    {"V1","V2","V1","V4","V2","V3","V3","V1","V3","V6","V4","V3","V4","V6","V5","V4","V6","V1","V6","V5","V6","V3"};
    return str[wk++];
}
int ww=0;
int PopWeight()                  //压出权值
{   
	if(ww>=11) 
    { ww=0; cout<<"ww归零";  }
	int wei[11]={5,7,4,8,9,5,6,5,3,1,9};
	return wei[ww++];
}
int wn=0;
string InitVexList()         //初始化顶点表
{   if(wn>=6)
    { wn=0;cout<<"wn归零"<<endl;  }
	string str[6]={"V1","V2","V3","V4","V5","V6"};
	return str[wn++];
}
int LocateVex(ALGraph &G,string &v1)
{   
	for(int i=0;i<=G.vexnum;i++)
		if(i==G.vexnum)
		{ cout<<"输入错误"<<endl; exit(0);  }
		else
			if(v1==G.vertices[i].data) return i;
}
void CreateDG(ALGraph &G)   //采用邻接表表示法，创建有向图G
{
	G.vexnum=6;  G.arcnum=11;  //6个顶点，11条边
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
		p->weight=PopWeight();
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
}

int RAdjvex(ALGraph &G,int v)                   //返回邻接点的下标
{ 
	ArcNode *p=G.vertices[v].firstarc;
	while(p)
	{
		if(!G.vertices[p->adjvex].m) break;
		else
			p=p->nextarc;
	}
	if(p)
	return p->adjvex;
	else
		return -1;
}

void BFS(ALGraph &G,int v=0)
{  
	SQueue Q;
	cout<<G.vertices[v].data<<" ";
	G.vertices[v].m=true;
	InitQueue(Q);
	EnQueue(Q,v); 
	while(Q.que[Q.front]>=0)
	{   
		int u=DeQueue(Q);
		int w=RAdjvex(G,u);
		for(w;w>=0;w=RAdjvex(G,u))
		{
			if(!G.vertices[w].m)
			{
				cout<<G.vertices[w].data<<" ";
				G.vertices[w].m=true;
				EnQueue(Q,w);
			}
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
	cout<<"遍历结果："<<endl;
	BFS(G);

	system("pause");
	return 0;
}



	

	
