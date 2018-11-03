// 
// @ClassName UglyNumberIIOffer
// @Description leetcode 264, 返回第n个丑数
// @Date 18-11-3 上午11:38
// @Created by Insomnia
//

#include <vector>
#include <climits>
#include <iostream>

using namespace std;
class Solution {
public:
    int nThUglyNum(int n) {
        if (n <= 0) {
            //= 0
            return false;
        }
        if (n == 1) {
            // = 1
            return true;
        }

        int t2 = 0, t3 = 0, t5 = 0;

        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i]  = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if (dp[i] == dp[t2]*2) {
                t2++;
            }
            if (dp[i] == dp[t3]*3) {
                t3++;
            }
            if (dp[i] == dp[t5]*5) {
                t5++;
            }
        }

        return dp[n - 1];
    }
};


int main() {
    int a = 6;
    int b = 8;
    int c = 10;

    Solution solution;
    cout <<  a << " " << boolalpha << solution.nThUglyNum(a) << endl;
    cout <<  b << " " << boolalpha << solution.nThUglyNum(b) << endl;
    cout <<  c << " " << boolalpha << solution.nThUglyNum(c) << endl;
    return 0;
}
