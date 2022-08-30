//最短路径—迪杰斯特拉算法
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int MaxWeight=1000;          //Max表示极大值
const int MVNum=6;          //MVNum表示最大顶点数
typedef string VerTexType;   //定义顶点为字符型数据
typedef int ArcType;         //定义边为整形数据
string InitVexList();        //函数声明；
struct Vex
{
	string str;
	bool m;
};	
struct AMGraph        
{
   Vex vex[MVNum];         //顶点表；
   ArcType arcs[MVNum][MVNum];    //邻接矩阵
   int vexnum,arcnum;             //图当前的顶点数和边数
};
struct 
{
	bool S;             //用于判断是否为最短路径
	int Distance;         //记录到最短路径的长度
	int Paht;          //记录终点的直接前驱
}VexCorde[MVNum];
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
	if(wk>=16)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[16]=
    {"V0","V2","V0","V4","V0","V5","V1","V2","V2","V3","V3","V5","V4","V3","V4","V5"};
    return str[wk++];
}
int iw=0;
int InitWeight()
{   
    int m[8]={10,30,100,5,50,10,20,60};
	
	return m[iw++];
}
void CreateUDN(AMGraph &G)                 //采用邻接矩阵表示法，创建有向网G
{
	G.vexnum=6;                            //有6个顶点；
	G.arcnum=8;                           //有8条边；
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
	    G.arcs[i][j]=InitWeight();
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
	VerTexType str[6]={"V0","V1","V2","V3","V4","V5"};
	return str[wn++];
}

void ShortestPath_DIJ(AMGraph &G,int xu=0)
{   
	int n=G.vexnum;
	for(int i=0;i<n;i++)
	{
		VexCorde[i].S=false;
		VexCorde[i].Distance=G.arcs[xu][i];
		if(VexCorde[i].Distance<MaxWeight) VexCorde[i].Paht=0;
		else
		VexCorde[i].Paht=-1;
	}
	VexCorde[xu].S=true;
	VexCorde[xu].Distance=0;              
	//初始化完毕
	for(int i=1;i<n;i++)
	{
	    int v=0;
		int min=MaxWeight;
		for(int w=0;w<n;w++) 
	    if(!VexCorde[w].S&&VexCorde[w].Distance<min)
		{  v=w;min=VexCorde[w].Distance;  }
			VexCorde[v].S=true;
			for(int i=0;i<n;i++)
			if(!VexCorde[i].S&&VexCorde[v].Distance+G.arcs[v][i]<VexCorde[i].Distance)
				{   
					VexCorde[i].Distance=VexCorde[v].Distance+G.arcs[v][i];
					VexCorde[i].Paht=v;
				}				   			
	}
	for(int i=0;i<n;i++)
	{
		if(i==xu)  continue;
		cout<<G.vex[xu].str<<"->"<<G.vex[i].str<<"：";
		if(VexCorde[i].Distance==MaxWeight)
			cout<<"无穷大"<<endl;
		else cout<<VexCorde[i].Distance<<endl;
	}
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	cout<<"关系矩阵："<<endl;
	Output(G);
	cout<<endl;
	cout<<"最短路径为："<<endl;
	ShortestPath_DIJ(G);

	system("pause");
	return 0;
}

	