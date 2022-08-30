/*有序表的合并*/
#include<iostream>
using namespace std;

struct Space
{
	int m;        //设计一个空间
};
struct List
{
	Space *elem;
};

void CreateList(List &a,List &b)
{
	a.elem=new Space[4];
	b.elem=new Space[7];
	a.elem[0].m=3;
	a.elem[1].m=5;
	a.elem[2].m=8;
	a.elem[3].m=11;

	b.elem[0].m=2;
	b.elem[1].m=6;
	b.elem[2].m=8;
	b.elem[3].m=9;
	b.elem[4].m=11;
	b.elem[5].m=15;
	b.elem[6].m=20;

	int i;
	cout<<"LA："<<" ";
	for(i=0;i<4;i++)
	{
		cout<<a.elem[i].m<<"  ";
	}
	cout<<endl<<"LB："<<" ";
	for(i=0;i<7;i++)
	{
		cout<<b.elem[i].m<<"  ";
	}
}

void And(List &a,List &b)
{
	Space *pa;
	Space *pb;
	List c;
	c.elem=new Space[11];
	pa=a.elem;
	pb=b.elem;
	int n=0,i=0,j=0;
	while(n<=3&&i<=6)
	{
		if(a.elem[n].m<=b.elem[i].m)
			{  c.elem[j].m=a.elem[n].m;
				j++;   n++; 
		}
		else
		{	c.elem[j].m=b.elem[i].m;
		     j++;   i++;
		}
}
while(n<4)
{  c.elem[j].m=a.elem[n].m;
    n++;
	j++;
}
while(i<7)
{
	c.elem[j].m=b.elem[i].m;
  i++;
  j++;
}
cout<<endl<<"LC："<<" ";
        for(i=0;i<11;i++)
     {
		 
	cout<<c.elem[i].m<<"  ";
          }
}

int main()
{
	List a;
	List b;
	CreateList(a,b);
	And(a,b);
	
system("pause");
return 0;
}
