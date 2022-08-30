/BF算法
#include<iostream>
using namespace std;

struct String
{
	char *ch;
	int length;
};

void InitS(String &S)            //主串
{
	S.ch="ababcabcacbab";
	S.length=strlen(S.ch);	
}
void InitT(String &T)            //子串
{
	T.ch="cacbab";
	T.length=strlen(T.ch);
}

void BF(String &S,String &T)
{
	int i=0,j=0;
	while(i<S.length&&j<T.length)
	{
		if(S.ch[i]==T.ch[j]) {++i;++j;}
		else  { i=i-j+1;j=0;}
	}
	if(j>=T.length) cout<<i-T.length+1;
	else 
		cout<<"无结果!";
}



int main()
{
	String S;
	String T;
	InitS(S);
	InitT(T);
	BF(S,T);

	system("pause");
	return 0;
}
