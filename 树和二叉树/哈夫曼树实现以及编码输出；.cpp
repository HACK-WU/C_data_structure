//哈夫曼树实现以及编码输出；
#include<iostream>
#include<string>
using namespace std;
struct HTNode
{
	int weight;
	int parent,Lchild,Rchild,Tag;
};

typedef HTNode *HuffmanTree;

int Leaf_n=-1;
int InitWeight()
{   Leaf_n++;
	int a[]={5,29,7,8,14,23,3,11};
	return a[Leaf_n];
}

int Select(HTNode *b)         //查找最小值序号；
{   int s,xu;
   int n=1;
    while(b[n].Tag!=0)  n++;
	s=b[n].weight; xu=n;
	for(int k=1;k<=14;k++)
	{   
		if(b[k].Tag==0)
		for(int j=k+1;j<=15;j++)
		{   
			if(b[j].Tag==0)
			if(b[j].weight<b[k].weight )			
				if(b[j].weight <s)
				{   
					s=b[j].weight ;  xu=j;
				}			
		}
	}
	b[xu].Tag=1;  
	return xu;
}
void CreateHuffmanTree(HuffmanTree &HT)    //构造哈夫曼树
{    const int n=8;
	if(n<=1) { cout<<"错误"; exit(0);}
	int m=2*n-1;
	HT=new HTNode[m+1];
	for(int i=1;i<=m;i++)
	{
		HT[i].parent=0;
		HT[i].Lchild=0;
		HT[i].Rchild=0;
		HT[i].Tag=0;
	}
    for(int i=1,k=0;i<=n;i++,k++)
	{  HT[i].weight=InitWeight(); }
	for(int i=9;i<16;i++)
	{  HT[i].weight=1000;}
	int s1,s2;
	for(int i=n+1;i<=m;i++)
	{
		s1=Select(HT);
		s2=Select(HT);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].Lchild=s1;
		HT[i].Rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		}
}
typedef char **HuffmanCode;
void CreateHuffmanCode(HuffmanTree &HT,HuffmanCode &HC)
{   
	HC=new char*[9];
	char *cd=new char[8];
	cd[7]='\0';
	for(int i=1;i<=8;i++)
	{   
		int start=7,c=i,f=HT[i].parent;
		while(f!=0)
		{  
			--start;
			if(HT[f].Lchild==c)  cd[start]='0';
			else
				cd[start]='1';
			c=f;f=HT[f].parent;
		}
		HC[i]=new char[8-start];
		strcpy(HC[i],&cd[start]);
	}
	delete cd;
}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC; 
	CreateHuffmanTree(HT);
	CreateHuffmanCode(HT,HC);
	cout<<"叶子结点分别为：5,29,7,8,14,23,3,11(已事先录入程序)"<<endl;
	cout<<"输出编码："<<endl;
	for(int i=1;i<=8;i++)
	{
	   cout<<i<<"："<<HC[i]<<endl;
	}
	 
	system("pause");
	return 0;
}


			

	

	
