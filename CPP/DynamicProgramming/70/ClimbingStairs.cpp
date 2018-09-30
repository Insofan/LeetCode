//
// Created by Insomnia on 2018/9/30.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbingStairs(int n) {
        if (n < 3) {
            return n;
        }
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);

        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

int main() {

    Solution solution;
    cout << solution.climbingStairs(3) << endl;
    return 0;
}
