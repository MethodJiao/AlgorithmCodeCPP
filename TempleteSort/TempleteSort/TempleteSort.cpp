// TempleteSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "algorithm_sort.h"
#include <stdlib.h>
#include "algorithm_search.h"


using namespace std;


struct MyStruct
{
	int num;
	double age;
};

template<class T>
bool Max(T a, T b)
{
	return a.num < b.num;
}

template<class T1, class T2>
int FindKey(T1 a, T2 b)
{
	if (a.num < b)
		return -1;
	if (a.num > b)
		return 1;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyStruct myStruct;
	myStruct.num = 12;
	myStruct.age = 1.;

	vector<MyStruct> data;
	data.push_back(myStruct);
	myStruct.num = 15;
	data.push_back(myStruct);
	myStruct.num = 9;
	data.push_back(myStruct);
	myStruct.num = 4;
	myStruct.age = 99;
	data.push_back(myStruct);
	myStruct.num = 7;
	myStruct.age = 1.;
	data.push_back(myStruct);
	myStruct.num = 16;
	data.push_back(myStruct);
	//归并排序
	//MergeSort(data.begin(), data.end(), Max<MyStruct>);

	//Lambda表达式写法
	MergeSort(data.begin(), data.end(), [](MyStruct a, MyStruct b) 
	{ 
		return a.num < b.num; 
	});
	
	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data[i].num << ' ';
		cout << endl;
	}
	////二分查找
	//vector<MyStruct>::iterator it = BinarySearch(data.begin(), data.end(), FindKey<MyStruct, int>, 4);

	//Lambda表达式写法
	vector<MyStruct>::iterator it = BinarySearch(data.begin(), data.end(), [](MyStruct mystruct, int num)
	{
		if (mystruct.num < num)
			return -1;
		if (mystruct.num > num)
			return 1;
		return 0;
	}, 4);

	cout << it->age << ' ';
	system("PAUSE");
	return 0;
}

