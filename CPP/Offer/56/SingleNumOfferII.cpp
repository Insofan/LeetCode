//
// Created by Insomnia on 2018/10/22.
// 同leetcode 260

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumIIOff(vector<int> vec) {
        int xval = 0;
        for (auto val : vec) {
            xval ^= val;
        }

        xval ^= xval & (xval - 1);
        vector<int> res(2, 0);

        for (auto num :vec) {
            if (xval & num) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};

int main() {
//    1,2,1,3,2,5
    int a[] = {1,2,1,3,2,5};
    vector<int> vec(&a[0], &a[6]);

    Solution solution;
    vector<int> res = solution.singleNumIIOff(vec);
    for (auto val : res) {
       cout << val << " ";
    }
    cout << endl;
    return 0;
}
