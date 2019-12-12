// VirtualRelease.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class BaseClass
{
public:
	BaseClass()
	{
		std::cout << "构造BaseClass" << std::endl;
	};
	virtual ~BaseClass()
	{
		std::cout << "析构BaseClass" << std::endl;
	};
};

class DerivedClass :public BaseClass
{
public:
	DerivedClass()
	{
		std::cout << "构造DerivedClass" << std::endl;
	};
	~DerivedClass()
	{
		std::cout << "析构DerivedClass" << std::endl;
	};
};


int main()
{
	BaseClass* b = new DerivedClass;
	delete b;
	//system("PAUSE");
}