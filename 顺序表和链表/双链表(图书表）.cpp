*******************************
*双链表--图书表,具有           *
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

struct Book;
typedef Book *Head_p;
void Contect(Head_p &L);
void BookList(Head_p &L);

struct Book
{
	string ID;
	string name;
	float price;
    struct Book *next;
	struct Book *prior;
};


void BookList(Head_p &L)//创建头结点,j=0;
{
	L=new Book;
	L->ID=("NULL");
	L->name=("NULL");
	L->price=NULL;
	L->next=NULL;
	L->prior=NULL;
}

void Input(Head_p &L,string &ID,string &name,float &price,int m)//图书录入，m表示录入的位置
{
	Book *p;
	p=L;int j=0;
	while(p&&j<(m-1))             //p不为空值，并查找第m-1个结点
	{
		p=p->next;    //p指向p 的下一个结点；
		j++;
	}
	if(!p||j>m-1) cout<<"ERROR"<<endl;
	
	Book *s;
	s=new Book;
	s->ID=ID;
	s->name=name;
	s->price=price;
	s->next=NULL;

	p->next=s;//两个结点连接，录入完成
	s->prior=p;
}

void SeekBook(Head_p &L)     //查找功能
{
	string name;
	cout<<"请输入要查询的书名：";cin>>name;
	Book *p;   p=L->next;
	while(p->name!=name)
	{
		p=p->next;
		if(!p)                       //如果p为空值，则查询无结果；
		{
			cout<<"查询无结果"<<endl;
			goto goon;
		}
	}
	cout<<endl<<"查询结果："<<endl
		<<"书名："<<p->name<<endl
		<<"价格："<<p->price<<endl
		<<"编号："<<p->ID<<endl;
goon: ;
	cout<<endl;
	void(*P)(Head_p &L);
	P=Contect;
	P(L);
}

void CreatBook(Head_p &L)  //插入图书
{
	int m;
	string name;
	float price;
	string ID;
	cout<<"书名：";cin>>name;
	cout<<endl<<"价格：";cin>>price;
	cout<<endl<<"编号：";cin>>ID;
	cout<<endl;

	Book *p;
	p=L->next;
	cout<<"请稍等......";
	while(p->next)            //p不为空值
	{
		p=p->next; //p指向p 的下一个结点；
		
	}

	Book *s;
	s=new Book;
	s->ID=ID;
	s->name=name;
	s->price=price;
	s->next=NULL;
	p->next=s;//连接
    cout<<"创建完成"<<endl;
	void(*P)(Head_p &L);
	P=Contect;
	P(L);
}

void DeleteBook(Head_p &L)
{
	string name;
	cout<<"请输入要删除的书名：";cin>>name;
	Book *p,*s;   p=L->next;
	while(p->name!=name)
	{
		p=p->next;
		if(!p)
		{
			cout<<"无此书！"<<endl;
			goto goon;
		}
	}
	s=p;                   //删除相应的图书
	p->prior->next=s->next;
	delete s;                
goon: ;
	cout<<endl;
	void(*P)(Head_p &L);
	P=Contect;
	P(L);
}

void ChangeBook(Head_p &L)  //更改图书
{
	string name;
	float price;
	string ID;
	cout<<"请输入要更改的书名：";   cin>>name;
	Book *p;   p=L->next;
	while(p->name!=name)
	{
		p=p->next;
		if(!p)
		{
			cout<<"无此书！"<<endl;
			goto goon;
		}
	}
	cout<<"书名：";cin>>name;
	cout<<"价格：";cin>>price;
	cout<<"编号：";cin>>ID;
	p->name=name;
	p->price=price;
	p->ID=ID;
goon: ;
cout<<endl;
void(*P)(Head_p &L);
	P=Contect;
	P(L);
}

void memu(Head_p &L)    //查看书目
{
	Book *p;
	p=L->next;
	while(p)
	{
		cout<<"书名";cout<<p->name;
		cout<<endl<<"价格：";cout<<p->price;
		cout<<endl<<"编号：";cout<<p->ID;
		cout<<endl<<endl;
		p=p->next;
	}
	cout<<endl;
	void(*P)(Head_p &L);
	P=Contect;
	P(L);
}

void Ability(Head_p &L)
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
			void(*p_Seek)(Head_p &L);//查询 
	        p_Seek=SeekBook;
			p_Seek(L);break;
		case 2:
	         void(*p_De)(Head_p &L);  //删除 2
	         p_De=DeleteBook;
			 p_De(L);break;
		case 3:
	         void(*p_CreateBook)(Head_p &L);//新增 3
	         p_CreateBook=CreatBook;
			 p_CreateBook(L);break;
		case 4:
	         void(*p_ChangeBook)(Head_p &L);//更改 4
           	 p_ChangeBook=ChangeBook;
			 p_ChangeBook(L);break;
		case 5:
			 void(*p_OutputBook)(Head_p &L);//查看目录 5
			 p_OutputBook=memu;
			 p_OutputBook(L);break;
		case 6:
			exit(1);
		default:
			 cout<<"ERROR"<<endl;
	}

}

void Contect(Head_p &L)
{
	int m;
	cout<<"返回主菜单： 1"<<endl
		<<"退出： 0"<<endl<<endl;
	cin>>m;
	switch(m)
	{
	case 1:
		void(*p)(Head_p &L);
		p=Ability;
		p(L);break;
	case 0:
		exit(1);break;
	default:
		cout<<"ERROR"<<endl;
		void(*P)(Head_p &L);
	    P=Contect;
	    P(L);
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
	
    Head_p L;                //创建头指针
	BookList(L);             //创建头结点
	Input(L,ID_1,name_1,price_1,1);//录入图书*验证成功*；
	Input(L,ID_2,name_2,price_2,2);
	Input(L,ID_3,name_3,price_3,3);
	Ability(L);

	system("pause");
	return 0;
} 