//
// Created by Insomnia on 2018/8/2.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {

        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = max(nums[0], nums[1]);
        dp[1] = dp[0];

        int n = nums.size();
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

int main() {
    
    
    Solution solution;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    
    cout << solution.rob(nums) << endl;

    return 0;
}
