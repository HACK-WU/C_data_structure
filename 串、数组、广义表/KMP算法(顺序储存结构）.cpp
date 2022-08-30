//KMP算法(顺序储存结构）
#include<iostream>
using namespace std;

struct String
{
	char *ch;
	int length;
};
struct Space
{
	int next[];
};

void InitS(String &S)            //主串
{
	S.ch="acabaabaabcacaabc";
	S.length=strlen(S.ch);	
}
void InitT(String &T)            //模式串
{
	T.ch="abaabcac";
	T.length=strlen(T.ch);
}

/*void Next(String &T,Space &Next)   //next函数
{
	int i=0,j=-1;Next.next[0]=-1;
	while(i<T.length)
	{
		if(j==-1||T.ch[i]==T.ch[j])
		{ 
			i++; j++; 
			Next.next[i]=j;
		}
		else    j=Next.next[j];
}
*/

void Nextval(String &T,Space &Next)  //next的修正函数；
{
	int i=0;Next.next[0]=-1;int j=-1;
	while(i<T.length)
	{
		if(j==-1||T.ch[i]==T.ch[j])
		{  
			i++;   j++;
			if(T.ch[i]!=T.ch[j])
				Next.next[i]=j;
			else
				Next.next[i]=Next.next[j];
		}
		else
			j=Next.next[j];
	}
}

void KMP(String &S,String &T,Space &Next) 
{
	int i=0,j=0;
	while(i<S.length&&j<T.length)
  {
	 if(j==-1||T.ch[j]==S.ch[i])
	{
		i++;  j++;
	}
	else
		j=Next.next[j];	
	}
	if(j>=T.length)
		cout<<i-T.length+1;
}



int main()
{  
	Space Next1;
	String S;
	String T;

	InitS(S); 
	InitT(T);

                Nextval(T,Next1);
	KMP(S,T,Next1);

	system("pause");
	return 0;
}