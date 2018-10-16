//
// Created by Insomnia on 2018/10/16.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using  namespace std;

class Solution {
public:
    int singleNumberII(vector<int> &nums) {
        int firBit = 0;
        int secBit = 0;

        for (auto val : nums) {
           int tmp = firBit;
           firBit = (firBit&~secBit&~val) | (~firBit&secBit&val);
           secBit = (~firBit&secBit&~val) | (~firBit&~secBit&val);
        }

        return firBit|secBit;
    }
};

int main() {
    int a[] = {2,2,3,2};
    vector<int> vector1(&a[0], &a[4]);
    Solution solution;
    cout << solution.singleNumberII(vector1) << endl;
    return 0;
}
