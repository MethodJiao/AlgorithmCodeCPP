#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//输入空间->暂存空间->输出空间

inline void algorithm(int n)
{
	int a = 0;               // O(1)
	vector<int> b(10000);    // O(1)
	if (n > 10)
		vector<int> nums(n); // O(n)
}

/* 结构体 */
struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

/* 函数 */
inline int func() {
	// do something...
	return 0;
}

/* 常数阶 */
inline void constant(int n)
{
	// 常量、变量、对象占用 O(1) 空间
	const int a = 0;
	int b = 0;
	vector<int> nums(10000);
	Node node(0);
	// 循环中的变量占用 O(1) 空间
	for (int i = 0; i < n; i++)
	{
		int c = 0;
	}
	// 循环中的函数占用 O(1) 空间
	for (int i = 0; i < n; i++)
	{
		//func();
	}
}

/* 线性阶 */
inline void linear(int n)
{
	// 长度为 n 的数组占用 O(n) 空间
	vector<int> nums(n);
	// 长度为 n 的列表占用 O(n) 空间
	vector<Node> nodes;
	for (int i = 0; i < n; i++)
	{
		nodes.push_back(Node(i));
	}
	// 长度为 n 的哈希表占用 O(n) 空间
	unordered_map<int, string> map;
	for (int i = 0; i < n; i++)
	{
		map[i] = to_string(i);
	}
}

/* 平方阶 */
inline void quadratic(int n)
{
	// 二维列表占用 O(n^2) 空间
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
/* 指数阶（建立满二叉树） */
inline TreeNode* buildTree(int n) {
	if (n == 0) return nullptr;
	TreeNode* root = new TreeNode(0);
	root->left = buildTree(n - 1);
	root->right = buildTree(n - 1);
	return root;
}

/* 对数阶（分治算法，例：归并排序，长度为n的数组可以形成高度为log2n的递归树） */

#pragma region 优选顺序结论
//  1 < log2N < n < n^2 < 2^n
#pragma endregion