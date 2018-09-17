//
// Created by Insomnia on 2018/9/17.
//

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

vector<int> randomVec(int len, int maxNum) {
    vector<int> res;
    srand(unsigned (time(NULL)));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        res.push_back(x);
    }
    return res;
}
class Solution {
public:
    vector<int> topKElem(vector<int> &vec, int k) {
        priority_queue<int , vector<int>, greater<int>> greatQueue;
        vector<int> res;
        for (int i = 0; i < vec.size(); ++i) {
            if (greatQueue.size() < k) {
                greatQueue.push(vec[i]);
            } else if (vec[i] > greatQueue.top()) {
                int top = greatQueue.top();
                greatQueue.pop();
                greatQueue.push(vec[i]);
                greatQueue.push(top);
            } else {
                greatQueue.push(vec[i]);
            }
        }
        while (res.size()<k) {
            res.push_back(greatQueue.top());
            greatQueue.pop();
        }
        return res;
    }
};

void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = randomVec(1000, 5000);
//    printVec(vec);
    /*
     * 第三种方法是分治法，将1亿个数据分成100份，每份100万个数据，找到每份数据中最大的10000个，最后在剩下的100*10000个数据里面找出最大的10000个。如果100万数据选择足够理想，那么可以过滤掉1亿数据里面99%的数据。100万个数据里面查找最大的10000个数据的方法如下：用快速排序的方法，将数据分为2堆，如果大的那堆个数N大于10000个，继续对大堆快速排序一次分成2堆，如果大的那堆个数N大于10000个，继续对大堆快速排序一次分成2堆，如果大堆个数N小于10000个，就在小的那堆里面快速排序一次，找第10000-n大的数字；递归以上过程，就可以找到第1w大的数。参考上面的找出第1w大数字，就可以类似的方法找到前10000大数字了。此种方法需要每次的内存空间为10^6*4=4MB，一共需要101次这样的比较。

        第四种方法是Hash法。如果这1亿个书里面有很多重复的数，先通过Hash法，把这1亿个数字去重复，这样如果重复率很高的话，会减少很大的内存用量，从而缩小运算空间，然后通过分治法或最小堆法查找最大的10000个数。

        第五种方法采用最小堆。首先读入前10000个数来创建大小为10000的最小堆，建堆的时间复杂度为O（mlogm）（m为数组的大小即为10000），然后遍历后续的数字，并于堆顶（最小）数字进行比较。如果比最小的数小，则继续读取后续数字；如果比堆顶数字大，则替换堆顶元素并重新调整堆为最小堆。整个过程直至1亿个数全部遍历完为止。然后按照中序遍历的方式输出当前堆中的所有10000个数字。该算法的时间复杂度为O（nmlogm），空间复杂度是10000（常数）。
     */
    Solution solution;
    vector<int> res = solution.topKElem(vec, 2);
    printVec(res);

    return 0;
}
