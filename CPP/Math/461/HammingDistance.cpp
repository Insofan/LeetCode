//
// Created by Insomnia on 2018/8/20.
//

//海明距离, 两个字符的二进制表示 不同的位数, 注意计算 二进制位为1 个数的技巧
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int n = x ^ y;

        while (n) {
            res++;
            n &= n - 1;
        }

        return res;
    }
};


int main() {

    Solution solution;
    cout << solution.hammingDistance(3, 10000) << endl;

    return 0;
}
