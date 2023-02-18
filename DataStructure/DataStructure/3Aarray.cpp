#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* �������һ������Ԫ�� */
inline int randomAccess(int* nums, int size) {
	// ������ [0, size) �������ȡһ������
	int randomIndex = rand() % size;
	// ��ȡ���������Ԫ��
	int randomNum = nums[randomIndex];
	return randomNum;
}
/* ��չ���鳤�� */
inline int* extend(int* nums, int size, int enlarge) {
	// ��ʼ��һ����չ���Ⱥ������
	int* res = new int[size + enlarge];
	// ��ԭ�����е�����Ԫ�ظ��Ƶ�������
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	// �ͷ��ڴ�
	delete[] nums;
	// ������չ���������
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

#pragma region ������ȱ����
//�����ڳ�ʼ���󳤶Ȳ��ɱ䣬�������Ĵ��ڴ�Ҳ�����˷�
//�ڴ漯�������ȡЧ�ʼ��ߣ��ó�����
#pragma endregion