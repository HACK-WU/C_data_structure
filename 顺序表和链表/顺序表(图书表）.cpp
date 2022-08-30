/*******************************
*顺序表--图书表,具有           *
*查找、删除、插入、更改和      *
*查看书目的功能；              *
*《数据结构》：ISBN_1;         *
*《程序设计》：ISBN_2;         *
*《毛泽东传》：ISBN_3;         *
*查找功能 1                    *             
*删除功能 2                    *
*新增功能 3                    *
*更改功能 4                    *
*查看书目功能 5               *
*******************************/
#include<iostream>
#include<string>
using namespace std;

struct BookList;
void Ability(BookList &L);

#define ERROR -1;
#define OK 1;
const int maxsize=3;   //图书表可能达到的最大长度
struct Book              //单个图书信息定义
{
	string ID;           //图书编号
	string name;         //图书名字
	float price;         //图书价格
};

struct BookList          //图书表目录的定义
{
	Book *elem;          //图书目录的基地址
	int length;          //目录的长度
};

int IninList(BookList &L)
{
	L.elem=new Book[20];//为图书目录分配一个大小为20的数组空间
	if(!L.elem)
		{
			L.length=0;  //如果失败空间长度为0
			exit(0);
	}                    //储存分配失败退出
	L.length=20;         //成功空间长度为20
	return OK;
}

void InputBook(BookList &L,string &ID_1,string &name_1,float &price_1,int &m) //录入图书信息
{
	L.elem[m].ID=ID_1;                 //录入编号
	L.elem[m].name=name_1;             //录入书名
	L.elem[m].price=price_1;           //录入价格
}

void SeekBook(BookList &L) //查询图书
{
	string name;
	cout<<"书名：";cin>>name;
	for(int i=0;i<=maxsize;i++)
	{
		if(L.elem[i].name==name)
			{
				ccout<<endl<<"查询结果："<<endl
					<<"书名："<<L.elem[i].name<<endl
					<<"编号："<<L.elem[i].ID<<endl
					<<"价格："<<L.elem[i].price<<endl
					<<endl;
				goto goon;
		}
	}
	cout<<"查询无结果"<<endl;cout<<endl;
goon:  ;

void(*p_1)(BookList &L);
p_1=Ability;
p_1(L);
}
		

void DeleteBook(BookList &L) //删除操作
{
	string name;
	cout<<"书名：";cin>>name;
	for(int i=0;i<=maxsize;i++)
	{
		if(L.elem[i].name==name)            //ID相同执行删除操作
		{
			for(int n=1;n<=maxsize;n++)
			{
		    	L.elem[i+n-1]=L.elem[i+1];
			}
		     goto goon;                //删除操作执行完毕，跳转至结束   
		}
		}
	cout<<"查找无结果"<<endl; cout<<endl;         //查询失败，反馈结果   
goon:  ;
	void(*p_1)(BookList &L);
p_1=Ability;
p_1(L);
}

void CreateBook(BookList &L)  //插入图书，并指定新增位子
{
	int m;
	cout<<"在序号几新增：";cin>>m;
	int n=maxsize;
	for(n;n>m-1;n--)
	{
		L.elem[n]=L.elem[n-1];
	}
	string ID;
	string name;
	float price;
	cout<<"请输入书名：";cin>>name;
	cout<<endl<<"请输入编号：";cin>>ID;
	cout<<endl<<"请输入价格：";cin>>price;
	L.elem[m-1].ID=ID;
	L.elem[m-1].name=name;
	L.elem[m-1].price=price;
	cout<<endl;
	void(*p_1)(BookList &L);
p_1=Ability;
p_1(L);
}

void ChangeBook(BookList &L)   //更改图书
{
	int m;
	cout<<"要更改图书的序号：";cin>>m;
	string ID;
	string name;
	float price;
	cout<<"请输入新书名：";cin>>name;
	cout<<endl<<"请输入编号：";cin>>ID;
	cout<<endl<<"请输入价格：";cin>>price;
	L.elem[m-1].ID=ID;
	L.elem[m-1].name=name;
	L.elem[m-1].price=price;
	cout<<endl;
	void(*p_1)(BookList &L);
p_1=Ability;
p_1(L);

}

void OutputBook(BookList &L)//显示书目
{  
	for(int i=0;i<=maxsize;i++)
	{
	cout<<i+1<<endl<<"书名："<<"<<"<<L.elem[i].name<<">>"<<endl
		<<"价格："<<L.elem[i].price<<endl
		<<"编号："<<L.elem[i].ID<<endl<<endl;
	}
	cout<<endl;
	void(*p_1)(BookList &L);
p_1=Ability;
p_1(L);
}

void Ability(BookList &L)    //功能实现
{

	int m;
	cout<<"功 能 表："<<endl
		<<"查询 1"<<endl
		<<"删除 2"<<endl
		<<"新增 3"<<endl
		<<"更改 4"<<endl
		<<"查看目录 5"<<endl
		<<"退出 6"<<endl
		<<endl<<"请输入你想要的操作功能的序号：";
	cin>>m;
	cout<<endl;
	switch(m)
		{

		case 1:
			void(*p_Seek)(BookList &L);//查询 
	        p_Seek=SeekBook;
			p_Seek(L);break;
		case 2:
	         void(*p_De)(BookList &L);  //删除 2
	         p_De=DeleteBook;
			 p_De(L);break;
		case 3:
	         void(*p_CreateBook)(BookList &L);//新增 3
	         p_CreateBook=CreateBook;
			 p_CreateBook(L);break;
		case 4:
	         void(*p_ChangeBook)(BookList &L);//更改 4
           	 p_ChangeBook=ChangeBook;
			 p_ChangeBook(L);break;
		case 5:
			 void(*p_OutputBook)(BookList &L);//查看目录 5
			 p_OutputBook=OutputBook;
			 p_OutputBook(L);break;
		case 6:
			exit(1);
		default:
			 cout<<"ERROR"<<endl;
	}

}

int main()
{
	string ID_1("ISBN_1");    //第一本书
	string name_1("数据结构");
	float price_1=35;
	int m_1=0;

	string ID_2("ISBN_2");    //第二本书
	string name_2("程序设计");
	float price_2=40;
	int m_2=1;

	string ID_3("ISBN_3");
	string name_3("毛泽东传");//第三本书
	float price_3=29;
	int m_3=2;
	
	string ID_4("NULL");     //第四本书
	string name_4("NULL");
	float price_4=0;
	int m_4=3;

    BookList L;
	IninList(L);
	InputBook(L,ID_1,name_1,price_1,m_1);//将图书录入图书表
	InputBook(L,ID_2,name_2,price_2,m_2);
	InputBook(L,ID_3,name_3,price_3,m_3);
	InputBook(L,ID_4,name_4,price_4,m_4);

	Ability(L);

	system("pause");
	return 0;
}








