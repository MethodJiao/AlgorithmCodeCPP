#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* ������ṹ�� */
struct ListNode {
	int val;         // ���ֵ
	ListNode* next;  // ָ����һ����ָ�루���ã�
	ListNode(int x) : val(x), next(nullptr) {}  // ���캯��
};
inline void init()
{
	/* ��ʼ������ 1 -> 3 -> 2 -> 5 -> 4 */
	// ��ʼ��������� 
	ListNode* n0 = new ListNode(1);
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(5);
	ListNode* n4 = new ListNode(4);
	// ��������ָ��
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
}

/* ������Ľ�� n0 ֮������� P */
void insert(ListNode* n0, ListNode* P) {
	ListNode* n1 = n0->next;
	P->next = n1;
	n0->next = P;
}

/* ɾ������Ľ�� n0 ֮����׸���� */
void remove(ListNode* n0) {
	if (n0->next == nullptr)
		return;
	// n0 -> P -> n1
	ListNode* P = n0->next;
	ListNode* n1 = P->next;
	n0->next = n1;
	// �ͷ��ڴ�
	delete P;
}

//������ʽ��Ч��????


/* ��������������Ϊ index �Ľ�� */
ListNode* access(ListNode* head, int index) {
	for (int i = 0; i < index; i++) {
		if (head == nullptr)
			return nullptr;
		head = head->next;
	}
	return head;
}


/* �������в���ֵΪ target ���׸���� */
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

/* ˫��������ṹ�� */
struct ListNode {
	int val;         // ���ֵ
	ListNode* next;  // ָ���̽���ָ�루���ã�
	ListNode* prev;  // ָ��ǰ������ָ�루���ã�
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}  // ���캯��
};