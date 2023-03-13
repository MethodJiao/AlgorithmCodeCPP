#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include <Queue>
using namespace std;
inline void initQuene()
{
	/* ��ʼ������ */
	queue<int> queue;

	/* Ԫ����� */
	queue.push(1);
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(4);

	/* ���ʶ���Ԫ�� */
	int front = queue.front();

	/* Ԫ�س��� */
	queue.pop();

	/* ��ȡ���еĳ��� */
	int size = queue.size();

	/* �ж϶����Ƿ�Ϊ�� */
	bool empty = queue.empty();
}

/* ��������ʵ�ֵĶ��� */
struct ListNode {
    int val;         // ���ֵ
    ListNode* next;  // ָ����һ����ָ�루���ã�
    ListNode(int x) : val(x), next(nullptr) {}  // ���캯��
};
class LinkedListQueue {
private:
    ListNode* front, * rear;  // ͷ��� front ��β��� rear 
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

    /* ��ȡ���еĳ��� */
    int size() {
        return queSize;
    }

    /* �ж϶����Ƿ�Ϊ�� */
    bool empty() {
        return queSize == 0;
    }

    /* ��� */
    void push(int num) {
        // β������� num
        ListNode* node = new ListNode(num);
        // �������Ϊ�գ�����ͷ��β��㶼ָ��ý��
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // ������в�Ϊ�գ��򽫸ý����ӵ�β����
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    /* ���� */
    void poll() {
        int num = peek();
        // ɾ��ͷ���
        ListNode* tmp = front;
        front = front->next;
        // �ͷ��ڴ�
        delete tmp;
        queSize--;
    }

    /* ���ʶ���Ԫ�� */
    int peek() {
        if (size() == 0)
            throw out_of_range("����Ϊ��");
        return front->val;
    }

    /* ������ת��Ϊ Vector ������ */
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

/* ���ڻ�������ʵ�ֵĶ��� */
class ArrayQueue {
private:
    int* nums;       // ���ڴ洢����Ԫ�ص�����
    int front;       // ����ָ�룬ָ�����Ԫ��
    int queSize;     // ���г���
    int queCapacity; // ��������

public:
    ArrayQueue(int capacity) {
        // ��ʼ������
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }

    ~ArrayQueue() {
        delete[] nums;
    }

    /* ��ȡ���е����� */
    int capacity() {
        return queCapacity;
    }

    /* ��ȡ���еĳ��� */
    int size() {
        return queSize;
    }

    /* �ж϶����Ƿ�Ϊ�� */
    bool empty() {
        return size() == 0;
    }

    /* ��� */
    void push(int num) {
        if (queSize == queCapacity) {
            cout << "��������" << endl;
            return;
        }
        // �����βָ�룬ָ���β���� + 1
        // ͨ��ȡ�������ʵ�� rear Խ������β����ص�ͷ��
        int rear = (front + queSize) % queCapacity;
        // �� num �������β
        nums[rear] = num;
        queSize++;
    }

    /* ���� */
    void poll() {
        int num = peek();
        // ����ָ������ƶ�һλ����Խ��β���򷵻ص�����ͷ��
        front = (front + 1) % queCapacity;
        queSize--;
    }

    /* ���ʶ���Ԫ�� */
    int peek() {
        if (empty())
            throw out_of_range("����Ϊ��");
        return nums[front];
    }

    /* ������ת��Ϊ Vector ������ */
    vector<int> toVector() {
        // ��ת����Ч���ȷ�Χ�ڵ��б�Ԫ��
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++) {
            arr[i] = nums[j % queCapacity];
        }
        return arr;
    }
};

//����Ӧ��
/*
�Ա��������������µ��󣬶����ͱ����뵽����֮�У����ϵͳ�ٸ���˳�����δ�������еĶ�����
��˫ʮһʱ���ڶ�ʱ���ڻ���������Ķ�������δ����߲��������ǹ���ʦ����Ҫ�ص�˼�������⡣

���ִ�������κ���Ҫʵ�֡������󵽡��Ĺ��ܣ������������, ��Ϣ���еȵȡ�
*/