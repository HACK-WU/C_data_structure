//折半、监哨顺序、查找
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct List
{
	int key;
};
struct SqList
{
	List *base;
	int length;
};
void InitSqList(SqList &L)
{
	L.base=new List[12];
	L.length=12;
	int m[11]={5,16,20,27,30,36,44,55,60,67,71};
	memcpy(L.base,m,sizeof(m));
	cout<<"序号：";
	for(int i=0;i<L.length;i++)
	{  cout<<i<<setw(4);  }
	cout<<endl<<"数值：";
	for(int i=0;i<L.length;i++)
	{ cout<<L.base[i].key<<setw(4);  } 
}
int  Search_Seq(SqList &L,int m)         //顺序查找
{
	for(int i=0;i<L.length;i++)
	{
		if(L.base[i].key==m) return i;
	}
	cout<<"查询失败";
	return 0;
}
int SearchSeq(SqList &L,int m)         //设置哨兵的顺序查找
{
	L.base[L.length-1].key=m;
	for(int i=0;i<L.length;i++)
	{
		if(L.base[i].key==m) return i;
	}
	cout<<"查询失败";
	return 0;
}
int Search_Bin(SqList &L,int m)       //折半查找
{
	int low=1;int high=L.length;
	while(low<L.length)
	{
		int mid=(low+high)/2-1;
		if(L.base[mid].key==m) return mid;
		else if(m<L.base[mid].key)  high=mid;
		else low=mid+2;
	}
	cout<<"查询失败";
	return 0;
}


int main()
{
	SqList L;
	InitSqList(L);
	cout<<endl<<"30的顺序查询结果为："<<Search_Seq(L,30);
	cout<<endl<<"100的设置哨兵的顺序查找为："<<SearchSeq(L,100);
	cout<<endl<<"30的折半查找为："<<Search_Bin(L,30);

	system("pause");
	return 0;
}
    

	


	

	
