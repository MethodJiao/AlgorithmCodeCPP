#include <iostream>
#include <queue>

using namespace std;

//小顶堆结点调整
void adjustMinHeap(vector<int> &nums, int root, int len) {
    int lch = 2 * root + 1;  //左子结点
    int rch = lch + 1;   //右子结点
    int index = root;  //较大结点

    if (rch < len && nums[rch] < nums[index])
        index = rch;

    if (lch < len && nums[lch] < nums[index])
        index = lch;

    if (index != root) //当前结点非最小结点
    {
        swap(nums[index], nums[root]);
        adjustMinHeap(nums, index, len);
    }
    return;
}

vector<int> TopKInHeap(vector<int> &nums, int k, int len) {
    vector<int> res(nums.begin(), nums.begin() + k); //取出前k个数

    for (int i = k / 2 - 1; i >= 0; i--)  //根据前K个数建立一个小顶堆
    {
        adjustMinHeap(res, i, k);
    }

    //将剩下的数与堆顶做比较
    for (int i = k; i < len; i++) {
        if (nums[i] > res[0])  //当前数比堆顶数大
        {
            res[0] = nums[i]; //将堆顶更新为该数
            adjustMinHeap(res, 0, k); //重新调整堆
        }
    }

    return res;
}

struct cmp1 {
    bool operator()(int &a, int &b) {
        return a > b;                                            //最小值优先
    }
};

int main() {
    //法一
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(6);
    vector<int> res = TopKInHeap(nums, 4, 5);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    //法二
//    int K = 0;
//    cin >> K;
//    int tmp = 0;
//    int i = 0;
//    priority_queue<int, vector<int>, cmp1> minHeap;            //建立最小优先队列
//    while (cin >> tmp) {									//循环输入数据流
//        if (i < K) {										//先建立一个K个大小的优先队列，也就是K大小的二叉堆
//            minHeap.push(tmp);
//        }
//        else {												//算法实现
//            if (tmp <= minHeap.top())
//                continue;
//            else if (tmp > minHeap.top()) {
//                minHeap.pop();
//                minHeap.push(tmp);
//            }
//        }
//        i++;
//    }
//    while (!minHeap.empty()) {								//输出最大的K个数
//        cout << minHeap.top() << endl;
//        minHeap.pop();
//    }
    return 0;
}