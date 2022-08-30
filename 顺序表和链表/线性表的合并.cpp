/*线性表的合并*/
#include<iostream>
using namespace std;

struct LA
{
	int a[4];
	
};

struct LB
{
	int a[3];
};

int Getlength(LA &a)
{
	int m=0;
	while(a.a[m]>=0)
	{
		m++;
	}
	return m;
}

int Getlength(LB &b)
{
	int m=0;
	while(b.a[m]>=0)
	{
		m++;
	}
	return m ;
}

void CreateList(LB &b,LA &a)
{
	 cout<<"表A长"<<Getlength(a)<<endl
		 <<"表B长"<<Getlength(b)<<endl;
	 int c[7];
	 int i,n,j=0;
	 for(i=0;i<4;i++)
	 {
		 c[i]=a.a[i];
	 }
	 for(i=0;i<3;i++)
	 {
		for(n=0;n<4;n++)
		{
			if(b.a[i]==a.a[n])
            {
			   goto goon;
			}

		}
		c[i+4]=b.a[i];
		j++;
		goon: ;
	 }
	 for(i=0;i<=4+j-1;i++)
	 {
		 cout<<c[i]<<"  ";
	 }
}


	

int main()
{
	LA a;
	LB b;
	a.a[0]=7;
	a.a[1]=5;
	a.a[2]=3;
	a.a[3]=11;
	b.a[0]=2;
	b.a[1]=6;
	b.a[2]=3;

CreateList(b,a);
	
	system("pause");
	return 0;
}
