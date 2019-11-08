#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// 基类/父类
class Base
{
public:
	void SetBase(int b)
	{
		_b = b;
	}

	void PrintBase()
	{
		cout << _b << endl;
	}
public:
	int _b;
};


// 派生类/子类
class Derived : public Base
{
public:
	int _d;
};


int main()
{
	// 派生类继承了基类中的成员变量
	cout << sizeof(Derived) << endl;

	// 派生类继承了基类中的成员函数
	Derived d;
	d.SetBase(10);
	d.PrintBase();
	return 0;
}
#endif


// 三种继承方式之间的区别：基类中不同访问权限的成员在子类中的权限
// public
// 基类/父类
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};


// 派生类/子类---一定要对基类进行扩展
// public继承方式：基类中public和protected访问权限修饰的成员在子类中的权限不变
//               基类中private修饰的成员在子类中不能直接访问 || 不可见---已经被继承到子类中
class Derived : public Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		// 基类中protected修饰的成员，在子类中的权限：protected
		_pro = proD;

		// public继承方式，基类中private成员在派生类中不能直接访问---不可见
		//_pri = priD;
	}

public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;
	}
};


int main()
{
	cout << sizeof(Derived) << endl;

	Derived d;
	d._pub = 10;
	//d._pro = 20;
	return 0;
}

