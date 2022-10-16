//#define _CRT_SECURE_NO_WARNINGS
//04.对象的生命周期
//-----------------00------------------------
// 01.对象的初始化
// *02.构造函数
// 03.析构函数
// 04.this指针（指向自己的，跟着类走的）

//---------------01------------------------------
//01.每一个对象，都是类的实例化
// 02.每一个对象，都可以有自己的数据
// 03.对象的数据需要进行初始化：
//      01.定义时赋值
//      02.类外直接赋值
//      03.调用接口赋值
//

//----------------02------------------------------
//初始化成员列表也是构造函数的一部分，是一种特殊的初始化方法
// 应用场景：
// 1.初始化一些必须初始化的数据成员，例如引用数据成员
// 2.初始化一些简单地数据成员
//

//----------------03--------------------------------
//析构函数
//主要在对象生命周期结束的时候，做一些清理工作 
//可以自己写，不写系统也会帮你写
//析构可以自动删除框架里面的成员，外面的delete删除的是框架和成员，且删除的只是对象成员的内存被泄露了，
//所以我们要在析构里面释放掉里面的内存成员避免内存泄露


//---------------04--------------------------------
//this指针每个类都有（包括空类都有this指针）（ps:空类也有1个字节）
//是系统自动产生的，且隐藏的，我们看不到定义但是可以使用
// 2.this指针并不是对象本身的一部分，他的作用域在类内，当类的普通对象在访问普通成员的时候，该指针总是指向调用者对象的
//

//---------------------------------010--------------------------
////第一种 直接复制
//class myclass1
//{
//	int data1 = 0;
//};
//
////第二种  类外赋值
//class myclass2
//{
//public:
//	int data2 ;
//};
//
////第三种 接口赋值
//class myclass3
//{
//	int data3;
//public:
//	void class3(int val)
//	{
//		data3 = val;
//	}
//};
//int main()
//{
//	//myclass2 my2;
//	//my2.data2 = 10;
//	myclass3 my3;
//	my3.class3(100);
//	return 0;
//}
//-------------------------------010---------------------------------

//------------------------------02-----------------------------------
//1.构造函数，他是一种特殊的函数
// 主要用来在创造对象时初始化对象，即为对象的成员变量赋初值 
// 也就是可以将对象在创立之初需要执行的逻辑写在函数中
// 
// 构造函数的调用实际
// 
// 
//

//-----------------020--------------------------------------
#include<iostream>
using namespace std;
class MyClass4
{
public:
	//构造函数
	int num;
	int& number;
	MyClass4();//无参构造
	MyClass4(int val);//带参数构造
	~MyClass4();//一般定义析构函数-无参且无返回值
private:

};

MyClass4::MyClass4():num(100),number(num) {}//这里面的代码块优先级更高，
//{
	//num = 100;
	//cout << "调用构造函数" << endl;
//}//可以防止内联的出现，节省内存
MyClass4::MyClass4(int val) :number(num), num(val)
{
	//num = val;
	cout << "调用构造函数2" << endl;
}
MyClass4::~MyClass4()
{
	cout << "调用析构" << endl;
}
class ca
{
public:
	ca()
	{
		cout << "ca" << endl;
	}

	~ca()
	{
		cout << "~ca" << endl;
	}
};
class cb
{
public:
	ca a;
	cb()
	{
		cout << "cb" << endl;
	}
	~cb()
	{
		cout << "~cb" << endl;
	}
};
class cc
{
	public:
		int *a;
	cc()
	{
		a = new int;
		cout << "cc" << endl;
	}
	~cc()
	{
		delete a;
		cout << "~cc" << endl;
	}
};
//---------------------03附属---------------析构和delete的区别-------------
class xigou
{
public:
	int* p;
	xigou()
	{
		p = new int;
	}
	void clear()
	{
		delete p;
		p = nullptr;
	}
	~xigou()
	{
		delete p;//这里可以不用赋空，因为等会这个类就会删除且，析构已经释放了类内部成员的内存
	}
};
//-----------------04-------------------------------------------------------------------
//1.可以避免重名，可以修改类内的数值
//2.能够在类内返回自身地址和本身
class cd
{
	int d;
public:
	cd()
	{
		this->d=100;
	}
	cd* get_this()
	{
		return this;
	}
	cd& get_self()
	{
		return *this;
	}
	int getcd()
	{
		return d;
	}
};
int main()
{
	//MyClass4 my4;
	//cout << my4.num << endl;
	//MyClass4 my5;
	//cout << my5.number << endl;
	//MyClass4 my4_2(10010);
	//cout << my4_2.num << endl;
	//MyClass4* my4_3 = new MyClass4(1022);
	//ca a;
	//cb b;
	//cc c;
	//cout << my4_3->num << endl;
	//cb b;
	//MyClass4 a(1);
	//cout << a.number << endl;
	//ca a;
	//cb b;
	//cc c;//析构的顺序和栈很像
	//cb b;//对象//可以调用构造和析构两个功能
	//cc* p1 = new cc;//只会调用构造
	//delete p1;//delete函数可以调用p1里的析构功能//只要使用了new就要用delete删掉，不然会浪费内存，会泄露int四个字节
	//析构是不能构成重载，析构函数里面不能有形参

	//cd d;
	//cout << &d << endl;//this表示的地址和变量命名时的变量相同
	//cout << d.get_this() << endl;

	//cout << &d.get_self().get_self().get_self() << endl;
	cd d2;
	d2.~cd();//系统调用的析构什么也没做，但如果你自己创立的一个析构可以自己选择释放掉int d
	cout << d2.getcd() << endl;

	return 0;
}