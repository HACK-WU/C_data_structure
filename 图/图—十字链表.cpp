//图—十字链表
#include<iostream>
#include<string>
using namespace std;
const int MVANum=10;
struct ArcNode
{
	int tailvex,headvex;   //该弧的尾和头的顶点位置
	ArcNode *hlink;        //指向弧头相同的弧
	ArcNode *tlink;        //指向弧尾相同的弧
};
struct VexNode
{
	string data;
	ArcNode *firstin;    //第一条入弧
	ArcNode *firstout;   //第一条出弧
};
struct OLGraph
{
	VexNode xlist[MVANum];
	int vexnum,arcnum;
};
int wk=0;                          
string PopVex()                   //压出顶点
{   
	if(wk>=14)
	{  wk=0;cout<<"wk归零"<<endl;  }
	string str[14]=
    {"V1","V2 ","V1","V3","V3","V4","V3","V1","V4","V2","V4","V3","V4","V1"};
    return str[wk++];
}
int wn=0;
string InitVexList()         //初始化顶点表
{   if(wn>=4)
    { wn=0;cout<<"wn归零"<<endl;  }
	string str[4]={"V1","V2","V3","V4"};
	return str[wn++];
}
int LocateVex(OLGraph &G,string &v1)
{   
	for(int i=0;i<G.vexnum;i++)
		if(i==G.vexnum)
		{ cout<<"输入错误"<<endl; exit(0);  }
		else
			if(v1==G.xlist[i].data) return i;
}
void CreateDG(OLGraph &G)
{
	G.vexnum=4;  G.arcnum=7;   //4个顶点，7条边
	for(int i=0;i<G.vexnum;i++)
    {
		G.xlist[i].data=InitVexList();
		G.xlist[i].firstin=NULL;
		G.xlist[i].firstout=NULL;
	}
	for(int k=0;k<G.arcnum;k++)
	{
		string v1,v2;int i,j;
		v1=PopVex(); i=LocateVex(G,v1);
		v2=PopVex(); j=LocateVex(G,v2);
		ArcNode *p=new ArcNode;
		p->tailvex=i;
		p->headvex=j;
		p->tlink=G.xlist[i].firstout;
		G.xlist[i].firstout=p;
	};	
	for(int i=0;i<G.vexnum;i++)
	   for(int k=0;k<G.vexnum;k++)
	   {  
          ArcNode *q=G.xlist[k].firstout;
		  while(q)
		    {
			if(q->headvex==i)
			  {
				cout<<G.xlist[q->tailvex].data<<" "<<G.xlist[i].data<<endl;
				q->hlink=G.xlist[k].firstin;
			    G.xlist[k].firstin=q;				
			  }
			    q=q->tlink;
		    }
	     }
}

int main()
{
	OLGraph G;
	CreateDG(G);

	system("pause");
	return 0;
}
