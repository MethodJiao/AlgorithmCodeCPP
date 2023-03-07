#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 链表结点结构体 */
struct ListNode {
	int val;         // 结点值
	ListNode* next;  // 指向下一结点的指针（引用）
	ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};
inline void init()
{
	/* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
	// 初始化各个结点 
	ListNode* n0 = new ListNode(1);
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(5);
	ListNode* n4 = new ListNode(4);
	// 构建引用指向
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
}

/* 在链表的结点 n0 之后插入结点 P */
void insert(ListNode* n0, ListNode* P) {
	ListNode* n1 = n0->next;
	P->next = n1;
	n0->next = P;
}

/* 删除链表的结点 n0 之后的首个结点 */
void remove(ListNode* n0) {
	if (n0->next == nullptr)
		return;
	// n0 -> P -> n1
	ListNode* P = n0->next;
	ListNode* n1 = P->next;
	n0->next = n1;
	// 释放内存
	delete P;
}

//链表访问结点效率????


/* 访问链表中索引为 index 的结点 */
ListNode* access(ListNode* head, int index) {
	for (int i = 0; i < index; i++) {
		if (head == nullptr)
			return nullptr;
		head = head->next;
	}
	return head;
}


/* 在链表中查找值为 target 的首个结点 */
int find(ListNode* head, int target) {
	int index = 0;
	while (head != nullptr) {
		if (head->val == target)
			return index;
		head = head->next;
		index++;
	}
	return -1;
}

/* 双向链表结点结构体 */
struct ListNode {
	int val;         // 结点值
	ListNode* next;  // 指向后继结点的指针（引用）
	ListNode* prev;  // 指向前驱结点的指针（引用）
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}  // 构造函数
};