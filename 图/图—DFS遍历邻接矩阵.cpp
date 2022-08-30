//图—DFS遍历邻接矩阵
#include<iostream>
#include<string>
using namespace std;
const int MaxInt=0;          //Max表示极大值
const int MVNum=10;          //MVNum表示最大顶点数
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
    {"V1","V2","V1","V4","V2","V3","V3","V1","V3","V6","V4","V3","V4","V6","V5","V4","V6","V1","V6","V5"};
    return str[wk++];
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
		{  G.arcs[i][j]=0; }          //初始化邻接矩阵，边的权值设为0；
		for(int k=0;k<G.arcnum;k++)
		{
		string v1,v2;   int i,j; 
		v1=PopVex();   i=LocateVex(G,v1); 
		v2=PopVex();   j=LocateVex(G,v2);  //确定v1和v2在G中的位置，即数组下标
	    G.arcs[i][j]=1;
		}   
}

void Output(AMGraph &G)
{   
	cout<<"   ";
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<G.vex[i].str<<" ";
	}
	cout<<endl;
	for(int i=0;i<G.vexnum;i++)
	 {   cout<<G.vex[i].str<<" ";
		 for(int k=0;k<G.vexnum;k++)
	    {  cout<<G.arcs[i][k]<<"  ";}
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

void DFS_AM(AMGraph &G,int i=0)
{
	cout<<G.vex[i].str<<" ";
	G.vex[i].m=1;
	for(int w=0;w<G.vexnum;w++)
	{   
		if((G.arcs[i][w]==1)&&(!G.vex[w].m))
		DFS_AM(G,w);
	}
}



int main()
{
	AMGraph G;
	CreateUDN(G);
	Output(G);
	cout<<endl;
	DFS_AM(G,1);
	

	system("pause");
	return 0;
}
