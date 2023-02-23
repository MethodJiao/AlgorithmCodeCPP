//��һ�� ʱ�临�Ӷ�
#include<vector>
using namespace std;

/* ������ */
inline int constant(int n)
{
	int count = 0;
	int size = 100;
	for (int i = 0; i < size; i++)
		count+=n;
	return count;
}

/* ���Խ� */
inline int linear(int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count++;
	return count;
}

/* ���Խף��������飩 */
inline int arrayTraversal(vector<int>& nums)
{
	int count = 0;
	// ѭ�����������鳤�ȳ�����
	for (int num : nums)
	{
		count++;
	}
	return count;
}

/* ƽ���� */
inline int quadratic(int n)
{
	int count = 0;
	// ѭ�����������鳤�ȳ�ƽ����ϵ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			count++;
		}
	}
	return count;
}

/* ƽ���ף�ð������ */
inline int bubbleSort(vector<int>& nums)
{
	int count = 0;  // ������
	// ��ѭ����������Ԫ������Ϊ n-1, n-2, ..., 1
	for (size_t i = nums.size() - 1; i > 0; i--)
	{
		// ��ѭ����ð�ݲ���
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				// ���� nums[j] �� nums[j + 1]
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
				count += 3;  // Ԫ�ؽ������� 3 ����Ԫ����
			}
		}
	}
	return count;
}

/* ָ���ף�ѭ��ʵ�֣� */
inline int exponential(int n)
{
	int count = 0, base = 1;
	// cell ÿ��һ��Ϊ�����γ����� 1, 2, 4, 8, ..., 2^(n-1)
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

/* ָ���ף��ݹ�ʵ�֣� */
inline int expRecur(int n)
{
	if (n == 1)
		return 1;
	return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* �����ף�ѭ��ʵ�֣� */
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

/* �����ף��ݹ�ʵ�֣� */
inline int logRecur(float n)
{
	if (n <= 1)
		return 0;
	return logRecur(n / 2) + 1;
}

/* ���Զ����� */
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

/* �׳˽ף��ݹ�ʵ�֣� */
inline int factorialRecur(int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	// �� 1 �����ѳ� n ��
	for (int i = 0; i < n; i++)
	{
		count += factorialRecur(n - 1);
	}
	return count;
}


#pragma region ��ѡ˳�����
//  1 < log2N < n < n * Log2N < n^2 < 2^n < n!
#pragma endregion