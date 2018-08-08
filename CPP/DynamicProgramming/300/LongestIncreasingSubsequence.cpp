//
// Created by Insomnia on 2018/8/7.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int res = 1;
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }

            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
