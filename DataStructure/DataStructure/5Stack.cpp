#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

inline void initStack()
{
	/* ��ʼ��ջ */
	stack<int> stack;

	/* Ԫ����ջ */
	stack.push(1);
	stack.push(3);
	stack.push(2);
	stack.push(5);
	stack.push(4);

	/* ����ջ��Ԫ�� */
	int top = stack.top();

	/* Ԫ�س�ջ */
	stack.pop(); // �޷���ֵ

	/* ��ȡջ�ĳ��� */
	int size = stack.size();

	/* �ж��Ƿ�Ϊ�� */
	bool empty = stack.empty();
}

/* ��������ʵ�ֵ�ջ */
class ArrayStack {
private:
    vector<int> stack;

public:
    /* ��ȡջ�ĳ��� */
    int size() {
        return stack.size();
    }

    /* �ж�ջ�Ƿ�Ϊ�� */
    bool empty() {
        return stack.empty();
    }

    /* ��ջ */
    void push(int num) {
        stack.push_back(num);
    }

    /* ��ջ */
    void pop() {
        int oldTop = top();
        stack.pop_back();
    }

    /* ����ջ��Ԫ�� */
    int top() {
        if (empty())
            throw out_of_range("ջΪ��");
        return stack.back();
    }

    /* ���� Vector */
    vector<int> toVector() {
        return stack;
    }
};

/* ��������ʵ�ֵ�ջ */
struct ListNode {
    int val;         // ���ֵ
    ListNode* next;  // ָ����һ����ָ�루���ã�
    ListNode(int x) : val(x), next(nullptr) {}  // ���캯��
};
class LinkedListStack {
private:
    ListNode* stackTop; // ��ͷ�����Ϊջ��
    int stkSize;        // ջ�ĳ���

public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
    }

    /* ��ȡջ�ĳ��� */
    int size() {
        return stkSize;
    }

    /* �ж�ջ�Ƿ�Ϊ�� */
    bool empty() {
        return size() == 0;
    }

    /* ��ջ */
    void push(int num) {
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    /* ��ջ */
    void pop() {
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        // �ͷ��ڴ�
        delete tmp;
        stkSize--;
    }

    /* ����ջ��Ԫ�� */
    int top() {
        if (size() == 0)
            throw out_of_range("ջΪ��");
        return stackTop->val;
    }

    /* �� List ת��Ϊ Array ������ */
    vector<int> toVector() {
        ListNode* node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
//ʱ��Ч��?
//�ռ�Ч��?

//����Ӧ��
/*
������еĺ�����ǰ��������еĳ����뷴������ÿ�����Ǵ��µ���ҳ��
������ͽ���һ����ҳִ����ջ���������ǾͿ���ͨ�������ˡ��������ص���һҳ�棬
���˲���ʵ��������ִ�г�ջ�����Ҫͬʱ֧�ֺ��˺�ǰ������ô����Ҫ����ջ�����ʵ�֡�

�����ڴ����ÿ�����ú���ʱ��ϵͳ�ͻ���ջ�����һ��ջ֡��
������¼��������������Ϣ���ڵݹ麯���У����µ��ƻ᲻��ִ����ջ�����ϻ��ݽ׶�ʱ��ջ��*/