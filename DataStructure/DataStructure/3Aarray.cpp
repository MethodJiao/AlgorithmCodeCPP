#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 随机返回一个数组元素 */
inline int randomAccess(int* nums, int size) {
	// 在区间 [0, size) 中随机抽取一个数字
	int randomIndex = rand() % size;
	// 获取并返回随机元素
	int randomNum = nums[randomIndex];
	return randomNum;
}
/* 扩展数组长度 */
inline int* extend(int* nums, int size, int enlarge) {
	// 初始化一个扩展长度后的数组
	int* res = new int[size + enlarge];
	// 将原数组中的所有元素复制到新数组
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	// 释放内存
	delete[] nums;
	// 返回扩展后的新数组
	return res;
}

inline void vectorAccess()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		int a = *it;
	}
}
inline void vectorDelete()
{
	vector<int> vec;
	//vec.resize(100);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); )
	{
		if (*it == 2)
		{
			it = vec.erase(it);
		}
		else
		{
			++it;
		}
	}
}
inline void vectorSort()
{
	vector<int> vec;
	//vec.resize(100);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	sort(vec.begin(), vec.end(), [](int a, int b)
		{
			return a > b;
		});
	sort(vec.begin(), vec.end(), greater<int>());
}

#pragma region 数组优缺结论
//数组在初始化后长度不可变，拷贝消耗大，内存也可能浪费
//内存集中随机读取效率极高，擅长查找
#pragma endregion