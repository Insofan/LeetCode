//
// Created by Insomnia on 2018/7/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > result;
        int allSet = 1 << nums.size();
        for (int i = 0; i < allSet; ++i) {
           vector<int> item;
            for (int j = 0; j < nums.size(); ++j) {
               if (i & (1 << j)) {
                   item.push_back(nums[j]);
               }
            }
            result.push_back(item);
        }
        return result;
    }

};


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>> res;
    Solution sol;
    res = sol.subsets(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
