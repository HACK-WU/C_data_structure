//最小生成树-普里姆算法
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
struct ClosedNode
{
	int adjvex;            //返回在U中最小边的顶点的序号(在G.vex[]中）
	int lowcost;           //最小边上的权值
};
typedef ClosedNode Closedge[MVNum]; //定义ClosedNode类型的辅助数组       

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

int Mini(Closedge &C)                     //返回Closedge中最小权值的下标
{  
	int xu=0;         
	while(C[xu].lowcost<1)
	{   xu++;  }
	int mini=C[xu].lowcost;
	for(int i=0;i<6;i++)
	{
		if(C[i].lowcost==0) continue;
		if(C[i].lowcost<mini)
		{  mini=C[i].lowcost;  xu=i;}
	}
	return xu;
}

void MiniSpanTree(AMGraph &G,Closedge&C,int xu=0)  
{ 
	for(int j=0;j<G.vexnum;j++)
	{
		if(j!=xu) 
		{  C[j].adjvex=xu; C[j].lowcost=G.arcs[xu][j];}
	}
		C[xu].lowcost=0;
        for(int i=1;i<G.vexnum;i++)
		{     
			int k=Mini(C);
			cout<<G.vex[C[k].adjvex].str  <<"->"<<G.vex[k].str<<"："<<G.arcs[C[k].adjvex][k];cout<<endl;
			C[k].lowcost=0;
		    for(int i=0;i<G.vexnum;i++)
				if(G.arcs[k][i]<C[i].lowcost)
				{   C[i].adjvex=k;  C[i].lowcost=G.arcs[k][i];}
		}

}
int main()
{
	AMGraph G;
	CreateUDN(G);
	Closedge C; 
	cout<<"关系矩阵："<<endl;
	Output(G);
	cout<<endl;
	cout<<"最小生成树为："<<endl;
	MiniSpanTree(G,C);

	system("pause");
	return 0;
}

	