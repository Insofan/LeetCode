//
// Created by Insomnia on 2018/7/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item);
        generate(0,nums,item, result);
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result) {
        if (i >= nums.size()) {
            return;
        }

        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1, nums, item, result);
        item.pop_back();
        generate(i+1, nums, item, result);

    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>>res;
    Solution sol;
     res =  sol.subsets(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
