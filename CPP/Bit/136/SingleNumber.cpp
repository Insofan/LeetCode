//
// Created by Insomnia on 2018/8/7.
//

#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
//这种做法 空间复杂性度超了
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]]++;
        }

        int res = -1;
        for (int i = 0; i < hashMap.size(); i++) {
            if (hashMap[i] == 1) {
                res = i;
            }
        }
        return res;
    }
};

int main() {
    int test1[7] = {4, 1, 2, 1, 2, 4, 9};
    vector<int> vec;
    for (int i = 0; i < 7; ++i) {
        vec.push_back(test1[i]);
    }

    Solution solution;
    cout << solution.singleNumber(vec) << endl;


    return 0;
}
