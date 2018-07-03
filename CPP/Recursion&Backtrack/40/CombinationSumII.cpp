//
// Created by Insomnia on 2018/7/3.
//
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > targetRes;
        vector<vector<int> > result;
        set<vector<int> > resSet;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        result.push_back(item);
        generate(0, candidates, item, result, resSet);
        for (int i = 0; i < result.size(); ++i) {
            int sum = 0;
            for (int j = 0; j <result[i].size(); ++j) {
                sum+=result[i][j];
            }
            if (sum == target) {
                targetRes.push_back(result[i]);
            }

        }
        return targetRes;

    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result, set<vector<int> > &resSet) {
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
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);

    vector<vector<int>> res;
    Solution sol;
    res = sol.combinationSum2(nums, 8);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}