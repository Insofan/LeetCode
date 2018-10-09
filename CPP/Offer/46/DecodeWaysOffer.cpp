// 
// Created by Insomnia on 18-10-9.
//

//同leetcode 91, 动态规划

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len + 1);
        dp[len] = 1;
        //从高位到地位是 0 - len, 如12258, 0是1, 4是8
        for (int i = len - 1; i >= 0 ; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                //动态规划, 低位加1位或者加两位
                dp[i] = dp[i + 1];
                //判断是否加两位, 十分位是1, 2 个位小于7, 二十六个字母
                if ((i < len - 1) && ((s[i] == '1' || s[i] == '2') && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return s.empty() ? 0 : dp[0];
    }
};

int main() {
   string str = "12258";
    //string str = "226";

   Solution solution;
   cout << solution.numDecodings(str) << endl;
    return 0;
}