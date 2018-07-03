//
// Created by Insomnia on 2018/7/3.
//

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        set<vector<int>> resSet;
        vector<int> item;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, item, result, resSet);
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result, set<vector<int>> &resSet) {
        if (i >= nums.size()) {
            return;
        }

        item.push_back(nums[i]);
        if (resSet.find(item) == resSet.end()) {
            result.push_back(item);
            resSet.insert(item);
        }
        generate(i + 1, nums, item, result, resSet);
        item.pop_back();
        generate(i + 1, nums, item, result, resSet);

    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);

    vector<vector<int>> res;
    Solution sol;
    res = sol.subsetsWithDup(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}