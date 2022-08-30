//分块查找
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct BSqList
{
	int *base;
	int *BSbase;
	int length;
};
void InitBSqList(BSqList &L)
{
	int m[18]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
	L.base=new int[19];
	memcpy(L.base+1,m,sizeof(m));
	L.length=18/3;
	int a[3]={22,48,86};
	L.BSbase=new int[3];
	memcpy(L.BSbase,a,sizeof(a));
	/*---------初始化完毕--------------*/
	cout<<"序号：";
	for(int i=1;i<=18;i++)
		cout<<i<<setw(4);
	cout<<endl<<"数值："<<setiosflags(ios::left);
	for(int i=1;i<=18;i++)
		cout<<setw(4)<<L.base[i];
	cout<<endl<<"索引表：";
	for(int i=0;i<3;i++)
	cout<<L.BSbase[i]<<" ";
}
int Search_BS(BSqList &L,int m)
{   cout<<endl;
	int n=L.length/3;
	if(m<=L.BSbase[0])
		for(int i=1;i<=n;i++)
			if(L.base[i]==m)  return i;
	if(m<=L.BSbase[1])
	{
		for(int i=7;i<=12;i++)
		{  
			if(L.base[i]==m) return i;
		}
		
	}
	else
		for(int i=13;i<18;i++)
			if(L.base[i]==m)  return i;
	cout<<"查询失败";
	return 0;
}
			

int main()
{
	BSqList L;
	InitBSqList(L);
	cout<<endl<<"44的分块查找为："
	<<Search_BS(L,44);

	system("pause");
	return 0;
}