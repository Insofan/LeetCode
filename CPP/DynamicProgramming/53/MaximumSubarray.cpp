//
// Created by Insomnia on 2018/8/2.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int maxRes = dp[0];

        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxRes) {
                maxRes = dp[i];
            }
        }

        return maxRes;

    }
};

int main() {

    Solution solution;
    vector<int> nums;

    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    cout << solution.maxSubArray(nums) << endl;

    return 0;
}
