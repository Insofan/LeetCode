//
// Created by Insomnia on 2018/8/13.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int fibnacci(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 1;
        if (n == 1) {
            return dp[0];
        }
        if ( n == 2) {
            return  dp[1];
        }

        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }
};
int main() {
    cout << "fib  6:" << endl;
    Solution solution;
    cout << solution.fibnacci(6);

    return 0;
}
