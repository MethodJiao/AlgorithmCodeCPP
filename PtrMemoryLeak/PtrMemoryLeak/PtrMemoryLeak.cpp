// PtrMemoryLeak.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct MyStruct
{
	int a = 1;
	char b = 'b';
	double c = 2.2;
};

void Method3()
{
	MyStruct* myStruct = new MyStruct();

}

void Method2(shared_ptr<MyStruct> myStructPtr)
{
	int a = myStructPtr->a;
}

void Method1()
{
	//MyStruct* s1 = new MyStruct();
	//Method2(shared_ptr<MyStruct>(s1));
}

int main()
{
	while (true)
	{
		//Method1();//bug

		//Method3();

		MyStruct* myStruct = new MyStruct();

		shared_ptr<MyStruct> myStructPtr(myStruct);

		//myStructPtr->a;
	}

}
