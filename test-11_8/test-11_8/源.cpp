#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// ����/����
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


// ������/����
class Derived : public Base
{
public:
	int _d;
};


int main()
{
	// ������̳��˻����еĳ�Ա����
	cout << sizeof(Derived) << endl;

	// ������̳��˻����еĳ�Ա����
	Derived d;
	d.SetBase(10);
	d.PrintBase();
	return 0;
}
#endif


// ���ּ̳з�ʽ֮������𣺻����в�ͬ����Ȩ�޵ĳ�Ա�������е�Ȩ��
// public
// ����/����
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


// ������/����---һ��Ҫ�Ի��������չ
// public�̳з�ʽ��������public��protected����Ȩ�����εĳ�Ա�������е�Ȩ�޲���
//               ������private���εĳ�Ա�������в���ֱ�ӷ��� || ���ɼ�---�Ѿ����̳е�������
class Derived : public Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;

		// ������protected���εĳ�Ա���������е�Ȩ�ޣ�protected
		_pro = proD;

		// public�̳з�ʽ��������private��Ա���������в���ֱ�ӷ���---���ɼ�
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

