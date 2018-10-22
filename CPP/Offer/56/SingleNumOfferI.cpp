//
// Created by Insomnia on 2018/10/22.
// 同leetcode 137, 三个数重复, 找出只出现一次的数字

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumbIOffer(vector<int> vec) {
        int a = 0;
        int b = 0;
        
        for (auto val : vec) {
           int tmp = a; 
           a = (a&~b&~val) + (~a&b&val);
           b = (~tmp&b&~val) + (~tmp&~b&val);
        }

        return a|b;
    }
};
int main() {
    int a[] = {2,2,3,2};
    vector<int> vec(&a[0], &a[4]);

    Solution solution;

    cout << solution.singleNumbIOffer(vec) << endl;

    return 0;
}
