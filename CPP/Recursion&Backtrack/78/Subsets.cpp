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
        generate(0, item, nums, result);
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

    return 0;
}
