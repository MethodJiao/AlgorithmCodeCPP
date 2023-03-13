#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include <Queue>
using namespace std;
inline void initQuene()
{
	/* 初始化队列 */
	queue<int> queue;

	/* 元素入队 */
	queue.push(1);
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(4);

	/* 访问队首元素 */
	int front = queue.front();

	/* 元素出队 */
	queue.pop();

	/* 获取队列的长度 */
	int size = queue.size();

	/* 判断队列是否为空 */
	bool empty = queue.empty();
}

/* 基于链表实现的队列 */
struct ListNode {
    int val;         // 结点值
    ListNode* next;  // 指向下一结点的指针（引用）
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};
class LinkedListQueue {
private:
    ListNode* front, * rear;  // 头结点 front ，尾结点 rear 
    int queSize;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    ~LinkedListQueue() {
        delete front;
        delete rear;
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool empty() {
        return queSize == 0;
    }

    /* 入队 */
    void push(int num) {
        // 尾结点后添加 num
        ListNode* node = new ListNode(num);
        // 如果队列为空，则令头、尾结点都指向该结点
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // 如果队列不为空，则将该结点添加到尾结点后
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    /* 出队 */
    void poll() {
        int num = peek();
        // 删除头结点
        ListNode* tmp = front;
        front = front->next;
        // 释放内存
        delete tmp;
        queSize--;
    }

    /* 访问队首元素 */
    int peek() {
        if (size() == 0)
            throw out_of_range("队列为空");
        return front->val;
    }

    /* 将链表转化为 Vector 并返回 */
    vector<int> toVector() {
        ListNode* node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

/* 基于环形数组实现的队列 */
class ArrayQueue {
private:
    int* nums;       // 用于存储队列元素的数组
    int front;       // 队首指针，指向队首元素
    int queSize;     // 队列长度
    int queCapacity; // 队列容量

public:
    ArrayQueue(int capacity) {
        // 初始化数组
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }

    ~ArrayQueue() {
        delete[] nums;
    }

    /* 获取队列的容量 */
    int capacity() {
        return queCapacity;
    }

    /* 获取队列的长度 */
    int size() {
        return queSize;
    }

    /* 判断队列是否为空 */
    bool empty() {
        return size() == 0;
    }

    /* 入队 */
    void push(int num) {
        if (queSize == queCapacity) {
            cout << "队列已满" << endl;
            return;
        }
        // 计算队尾指针，指向队尾索引 + 1
        // 通过取余操作，实现 rear 越过数组尾部后回到头部
        int rear = (front + queSize) % queCapacity;
        // 将 num 添加至队尾
        nums[rear] = num;
        queSize++;
    }

    /* 出队 */
    void poll() {
        int num = peek();
        // 队首指针向后移动一位，若越过尾部则返回到数组头部
        front = (front + 1) % queCapacity;
        queSize--;
    }

    /* 访问队首元素 */
    int peek() {
        if (empty())
            throw out_of_range("队列为空");
        return nums[front];
    }

    /* 将数组转化为 Vector 并返回 */
    vector<int> toVector() {
        // 仅转换有效长度范围内的列表元素
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++) {
            arr[i] = nums[j % queCapacity];
        }
        return arr;
    }
};

//经典应用
/*
淘宝订单。购物者下单后，订单就被加入到队列之中，随后系统再根据顺序依次处理队列中的订单。
在双十一时，在短时间内会产生海量的订单，如何处理「高并发」则是工程师们需要重点思考的问题。

各种待办事项。任何需要实现“先来后到”的功能，例如任务队列, 消息队列等等。
*/