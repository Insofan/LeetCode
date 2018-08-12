// 
// Created by Insomnia on 18-8-12.
//


/*
 * 修改数组方法
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateNumber(vector<int> & vec) {
        if (vec.size() == 0) {
            return -1;
        }

        if (vec.size() == 1) {
            return vec[0];
        }


        for (int i = 0; i < vec.size(); ++i) {
            while (vec[i] != i) {
                if (vec[i] == vec[vec[i]]) {
                    return vec[i];
                }

                swap(vec[i], vec[vec[i]]);
            }
        }

        return  -1;
    }
};
int main () {
    int nums[7] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> vec;
    for (int i = 0; i < 7; ++i) {
        vec.push_back(nums[i]);
    }

    Solution solution;

    cout << solution.duplicateNumber(vec) << endl;

    return  0;
}
