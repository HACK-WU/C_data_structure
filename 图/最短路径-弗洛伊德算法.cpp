//最短路径-弗洛伊德算法
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int MaxWeight=1000;          //Max表示极大值
const int MVNum=4;          //MVNum表示最大顶点数
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
struct  VexSet
{
	int D[MVNum][MVNum];
	int Path[MVNum][MVNum];
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
	if(wk>=16)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[16]=
    {"V0","V1","V0","V3","V1","V2","V1","V3","V2","V0","V2","V1","V2","V3","V3","V2"};
    return str[wk++];
}
int iw=0;
int InitWeight()
{   
    int m[8]={1,4,9,2,3,5,8,6};
	
	return m[iw++];
}
void CreateUDN(AMGraph &G)                 //采用邻接矩阵表示法，创建有向网G
{
	G.vexnum=4;                            //有4个顶点；
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
		for(int i=0;i<G.vexnum;i++)
			G.arcs[i][i]=0;
		
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
{   if(wn>=4)
    { wn=0;cout<<"wn归零"<<endl;  }
	VerTexType str[4]={"V0","V1","V2","V3"};
	return str[wn++];
}

void ShortestPath_Floyd(AMGraph &G)
{    
	VexSet V;
	for(int i=0;i<G.vexnum;i++)
		for(int j=0;j<G.vexnum;j++)
		{
			V.D[i][j]=G.arcs[i][j];
			if(V.D[i][j]<MaxWeight)  V.Path[i][j]=i;
			else  V.Path[i][j]=-1;
		}
		for(int k=0;k<G.vexnum;k++)
			for(int i=0;i<G.vexnum;i++)
				for(int j=0;j<G.vexnum;j++)
				  if(V.D[i][k]+V.D[k][j]<V.D[i][j])
					{
						V.D[i][j]=V.D[i][k]+V.D[k][j];
						V.Path[i][j]=V.Path[k][j];
					}
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
	    {  cout<<setw(8)<<V.D[i][k];}
	    cout<<endl;
	}
				
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	cout<<"关系矩阵："<<endl;
	Output(G);
	cout<<endl;
	cout<<"任意两点间的最短路径为："<<endl;
	ShortestPath_Floyd(G);

	system("pause");
	return 0;
}

	