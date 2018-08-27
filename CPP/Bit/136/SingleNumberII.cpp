//
// Created by Insomnia on 2018/8/27.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {


        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
           res = res ^ nums[i];
           cout << res << endl;
        }

        return res;
    }
};


int main() {
    int         test1[7] = {4, 1, 2, 1, 2, 9, 4};
    vector<int> vec;
    for (int    i        = 0; i < 7; ++i) {
        vec.push_back(test1[i]);
    }

    Solution solution;
    cout << solution.singleNumber(vec) << endl;
    return 0;
}
