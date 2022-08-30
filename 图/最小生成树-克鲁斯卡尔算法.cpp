//最小生成树-克鲁斯卡尔算法
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int MaxWeight=1000;          //Max表示极大值
const int MVNum=10;          //MVNum表示最大顶点数
typedef string VerTexType;   //定义顶点为字符型数据
typedef int ArcType;         //定义边为整形数据
string InitVexList();        //函数声明；
struct Vex
{
	string str;
	bool m;
};
struct
{
	int head;      //边的始结点的下标
	int tail;      //边的终点的下标
	int lowcost;   //边的权值
}Edge[10];
int Vexset[6];

struct AMGraph        
{
   Vex vex[MVNum];         //顶点表；
   ArcType arcs[MVNum][MVNum];    //邻接矩阵
   int vexnum,arcnum;             //图当前的顶点数和边数
};
int LocateVex(AMGraph &G,string &v1)
{   
	for(int i=0;i<=G.vexnum;i++)
		if(i==G.vexnum)
		{ cout<<"输入错误"<<endl; exit(0);  }
		else
			if(v1==G.vex[i].str) return i;
}
int wk=0;                          
string PopVex()                   //压出顶点
{   
	if(wk>=20)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[20]=
    {"V1","V2","V1","V3","V1","V4","V2","V3","V2","V5","V3","V4","V3","V5","V3","V6","V4","V6","V5","V6"};
    return str[wk++];
}
int iw=0;
int InitWeight()
{   
    int m[10]={6,1,5,5,3,5,6,4,2,6};
	
	return m[iw++];
}
void CreateUDN(AMGraph &G)                 //采用邻接矩阵表示法，创建有向网G
{
	G.vexnum=6;                            //有6个顶点；
	G.arcnum=10;                           //有10条边；
	for(int i=0;i<G.vexnum;i++)
	{  
		G.vex[i].str=InitVexList();        //输入顶点信息；
	    G.vex[i].m=false;
	}       
	for(int i=0;i<G.vexnum;i++)
		for(int j=0;j<G.vexnum;j++)
		{  G.arcs[i][j]=MaxWeight; }          //初始化邻接矩阵，边的权值设为0；
		for(int k=0;k<G.arcnum;k++)
		{
		string v1,v2;   int i,j; 
		v1=PopVex();   i=LocateVex(G,v1); 
		v2=PopVex();   j=LocateVex(G,v2);  //确定v1和v2在G中的位置，即数组下标
	   G.arcs[j][i]=G.arcs[i][j]=InitWeight();
		} 
		
}

void Output(AMGraph &G)
{   
	cout<<setiosflags(ios::left);
	cout<<setw(8)<<"V";
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<setw(8)<<G.vex[i].str;
	}
	cout<<endl;
	for(int i=0;i<G.vexnum;i++)
	 {   cout<<setw(8)<<G.vex[i].str;
		 for(int k=0;k<G.vexnum;k++)
	    {  cout<<setw(8)<<G.arcs[i][k];}
	    cout<<endl;
	}
}
int wn=0;
string InitVexList()                       //初始化顶点表
{   if(wn>=6)
    { wn=0;cout<<"wn归零"<<endl;  }
	VerTexType str[6]={"V1","V2","V3","V4","V5","V6"};
	return str[wn++];
}
void Sort(AMGraph &G)
{   int mini,a,b;
for(int k=0;k<G.arcnum;k++)
	{   mini=999;
		for(int i=0;i<G.vexnum;i++)
		{
			for(int j=i;j<G.vexnum;j++)			   
		    if(G.arcs[i][j]<1000) 		
		    if(mini>=G.arcs[i][j])
		     {  mini=G.arcs[i][j]; a=i;b=j; }	
	    }
		  G.arcs[a][b]=1000;
		  Edge[k].lowcost=mini;
		  Edge[k].head=a;
		  Edge[k].tail=b;
   }
}
		     
void MiniSpanTree_Kruskal(AMGraph &G)
{
	Sort(G);
	for(int i=0;i<G.vexnum;i++)
	  Vexset[i]=i;
	for(int i=0;i<G.arcnum;i++)
	{  
	   int v1=Edge[i].head;
	   int v2=Edge[i].tail;
	   int vs1=Vexset[v1];
	   int vs2=Vexset[v2];
	   if(vs1!=vs2)
	   {
		   cout<<G.vex[v1].str<<"->"<<G.vex[v2].str<<"："<<Edge[i].lowcost<<endl;
		   for(int j=0;j<G.vexnum;j++)
		   if(Vexset[j]==vs2)  Vexset[j]=vs1;
	   }
	}
}
int main()
{
	AMGraph G;
	CreateUDN(G);
	cout<<"关系矩阵："<<endl;
	Output(G);
	cout<<endl;
	cout<<"最小生成树为："<<endl;
	MiniSpanTree_Kruskal(G);

	system("pause");
	return 0;
}

	