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
        if (n < 2) {
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {

    cout << "Frog jump 10 ladder:" << endl;
    Solution solution;

    cout << solution.jumpFrog(3) << endl;

    return 0;
}
