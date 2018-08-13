//
// Created by Insomnia on 2018/8/13.
//

//同 leetcode 70

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFrog(int n) {
        vector<int> dp(n, -1);

        dp[0] = 1;
        dp[1] = 2;

        if (n < 2) {
            return dp[n - 1];
        }

        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n - 1];
    }
};

int main() {

    cout << "Frog jump 10 ladder:" << endl;
    Solution solution;

    cout << solution.jumpFrog(3) << endl;

    return 0;
}
