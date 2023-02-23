//第一讲 时间复杂度
#include<vector>
using namespace std;

/* 常数阶 */
inline int constant(int n)
{
	int count = 0;
	int size = 100;
	for (int i = 0; i < size; i++)
		count+=n;
	return count;
}

/* 线性阶 */
inline int linear(int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count++;
	return count;
}

/* 线性阶（遍历数组） */
inline int arrayTraversal(vector<int>& nums)
{
	int count = 0;
	// 循环次数与数组长度成正比
	for (int num : nums)
	{
		count++;
	}
	return count;
}

/* 平方阶 */
inline int quadratic(int n)
{
	int count = 0;
	// 循环次数与数组长度成平方关系
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			count++;
		}
	}
	return count;
}

/* 平方阶（冒泡排序） */
inline int bubbleSort(vector<int>& nums)
{
	int count = 0;  // 计数器
	// 外循环：待排序元素数量为 n-1, n-2, ..., 1
	for (size_t i = nums.size() - 1; i > 0; i--)
	{
		// 内循环：冒泡操作
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				// 交换 nums[j] 与 nums[j + 1]
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
				count += 3;  // 元素交换包含 3 个单元操作
			}
		}
	}
	return count;
}

/* 指数阶（循环实现） */
inline int exponential(int n)
{
	int count = 0, base = 1;
	// cell 每轮一分为二，形成数列 1, 2, 4, 8, ..., 2^(n-1)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < base; j++)
		{
			count++;
		}
		base *= 2;
	}
	// count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
	return count;
}

/* 指数阶（递归实现） */
inline int expRecur(int n)
{
	if (n == 1)
		return 1;
	return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* 对数阶（循环实现） */
inline int logarithmic(float n)
{
	int count = 0;
	while (n > 1)
	{
		n = n / 2;
		count++;
	}
	return count;
}

/* 对数阶（递归实现） */
inline int logRecur(float n)
{
	if (n <= 1)
		return 0;
	return logRecur(n / 2) + 1;
}

/* 线性对数阶 */
inline int linearLogRecur(float n)
{
	if (n <= 1)
		return 1;
	int count = linearLogRecur(n / 2) +
		linearLogRecur(n / 2);
	for (int i = 0; i < n; i++)
	{
		count++;
	}
	return count;
}

/* 阶乘阶（递归实现） */
inline int factorialRecur(int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	// 从 1 个分裂出 n 个
	for (int i = 0; i < n; i++)
	{
		count += factorialRecur(n - 1);
	}
	return count;
}


#pragma region 优选顺序结论
//  1 < log2N < n < n * Log2N < n^2 < 2^n < n!
#pragma endregion