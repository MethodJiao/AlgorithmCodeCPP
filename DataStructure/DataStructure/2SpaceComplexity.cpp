#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//����ռ�->�ݴ�ռ�->����ռ�

inline void algorithm(int n)
{
	int a = 0;               // O(1)
	vector<int> b(10000);    // O(1)
	if (n > 10)
		vector<int> nums(n); // O(n)
}

/* �ṹ�� */
struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

/* ���� */
inline int func() {
	// do something...
	return 0;
}

/* ������ */
inline void constant(int n)
{
	// ����������������ռ�� O(1) �ռ�
	const int a = 0;
	int b = 0;
	vector<int> nums(10000);
	Node node(0);
	// ѭ���еı���ռ�� O(1) �ռ�
	for (int i = 0; i < n; i++)
	{
		int c = 0;
	}
	// ѭ���еĺ���ռ�� O(1) �ռ�
	for (int i = 0; i < n; i++)
	{
		//func();
	}
}

/* ���Խ� */
inline void linear(int n)
{
	// ����Ϊ n ������ռ�� O(n) �ռ�
	vector<int> nums(n);
	// ����Ϊ n ���б�ռ�� O(n) �ռ�
	vector<Node> nodes;
	for (int i = 0; i < n; i++)
	{
		nodes.push_back(Node(i));
	}
	// ����Ϊ n �Ĺ�ϣ��ռ�� O(n) �ռ�
	unordered_map<int, string> map;
	for (int i = 0; i < n; i++)
	{
		map[i] = to_string(i);
	}
}

/* ƽ���� */
inline void quadratic(int n)
{
	// ��ά�б�ռ�� O(n^2) �ռ�
	vector<vector<int>> numMatrix;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			tmp.push_back(0);
		}
		numMatrix.push_back(tmp);
	}
}

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/* ָ���ף��������������� */
inline TreeNode* buildTree(int n) {
	if (n == 0) return nullptr;
	TreeNode* root = new TreeNode(0);
	root->left = buildTree(n - 1);
	root->right = buildTree(n - 1);
	return root;
}

/* �����ף������㷨�������鲢���򣬳���Ϊn����������γɸ߶�Ϊlog2n�ĵݹ����� */

#pragma region ��ѡ˳�����
//  1 < log2N < n < n^2 < 2^n
#pragma endregion