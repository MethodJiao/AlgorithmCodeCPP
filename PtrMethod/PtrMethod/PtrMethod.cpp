// PtrMethod.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MyClassA
{
public:
	MyClassA();
	~MyClassA();
	int Method1();
private:

};

MyClassA::MyClassA()
{
}

MyClassA::~MyClassA()
{
}

int MyClassA::Method1()
{
	int a = 0;
	return a;
}

class MyClassB
{
public:
	MyClassB();
	~MyClassB();
	int Method2(int (MyClassA ::* pMethod1)());
private:

};

MyClassB::MyClassB()
{
}

MyClassB::~MyClassB()
{
}

int MyClassB::Method2(int (MyClassA ::* pMethod1)())//以函数指针为参数的函数
{
	MyClassA myClassA;
	int a = (myClassA.*pMethod1)();//通过函数指针调用目标函数
	return a;
}

int main()
{
	int (MyClassA :: * pMethod1)() = &MyClassA::Method1;//函数指针初始化，格式：返回类型（函数指针变量名及作用域）（函数指针指向函数的参数）
	//pMethod1 = &MyClassA::Method1;//函数指针重定向

	MyClassB myClassB;
	myClassB.Method2(pMethod1);
}
