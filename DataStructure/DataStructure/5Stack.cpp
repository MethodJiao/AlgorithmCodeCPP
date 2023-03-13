#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

inline void initStack()
{
	/* 初始化栈 */
	stack<int> stack;

	/* 元素入栈 */
	stack.push(1);
	stack.push(3);
	stack.push(2);
	stack.push(5);
	stack.push(4);

	/* 访问栈顶元素 */
	int top = stack.top();

	/* 元素出栈 */
	stack.pop(); // 无返回值

	/* 获取栈的长度 */
	int size = stack.size();

	/* 判断是否为空 */
	bool empty = stack.empty();
}

/* 基于数组实现的栈 */
class ArrayStack {
private:
    vector<int> stack;

public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }

    /* 判断栈是否为空 */
    bool empty() {
        return stack.empty();
    }

    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }

    /* 出栈 */
    void pop() {
        int oldTop = top();
        stack.pop_back();
    }

    /* 访问栈顶元素 */
    int top() {
        if (empty())
            throw out_of_range("栈为空");
        return stack.back();
    }

    /* 返回 Vector */
    vector<int> toVector() {
        return stack;
    }
};

/* 基于链表实现的栈 */
struct ListNode {
    int val;         // 结点值
    ListNode* next;  // 指向下一结点的指针（引用）
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};
class LinkedListStack {
private:
    ListNode* stackTop; // 将头结点作为栈顶
    int stkSize;        // 栈的长度

public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
    }

    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }

    /* 判断栈是否为空 */
    bool empty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    /* 出栈 */
    void pop() {
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        // 释放内存
        delete tmp;
        stkSize--;
    }

    /* 访问栈顶元素 */
    int top() {
        if (size() == 0)
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    /* 将 List 转化为 Array 并返回 */
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
//时间效率?
//空间效率?

//典型应用
/*
浏览器中的后退与前进、软件中的撤销与反撤销。每当我们打开新的网页，
浏览器就将上一个网页执行入栈，这样我们就可以通过「后退」操作来回到上一页面，
后退操作实际上是在执行出栈。如果要同时支持后退和前进，那么则需要两个栈来配合实现。

程序内存管理。每当调用函数时，系统就会在栈顶添加一个栈帧，
用来记录函数的上下文信息。在递归函数中，向下递推会不断执行入栈，向上回溯阶段时出栈。*/