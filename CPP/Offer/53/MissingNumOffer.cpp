// 
// Created by Insomnia on 18-10-14.
// 同 leetcode 268, 同single number
// Missing Number
//这个题出的 有问题, 如果按照书上是排序数组, 而且每一个数和自己的index对应 直接for循环用nums[i[ 与 i 比较就行了, 返回i即可,根本不需要书上的各种代码
//第三问 还没写

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missNumber(vector<int> &nums) {
        //取一个数组中没有的数字
        int res = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }

};

int main() {
    int a[9] = {9,6,4,2,3,5,7,0,1};
    vector<int> vec(&a[0], &a[9]);
    Solution solution;
    cout << solution.missNumber(vec) << endl;
    return 0;
}

