#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-3 下午10:23
# @Author  : Insomnia
# @Desc    : Leetcode:
# @File    : RegExp.py
# @Software: PyCharm

class Solution:
    """
    @param s: A string
    @param p: A string includes "." and "*"
    @return: A boolean
    """
    def isMatch(self, s, p):
        # write your code here
        m = len(s)
        n = len(p)

        # dp = [[False] * (n + 1)] * (m + 1)
        #  用上面这种定义二维数组时, 如果写 dp[0][0] = true , 会将第一列都变成True, 因为Note also that the copies are shallow; nested
        # structures are not copied. This often haunts new Python programmers; consider, 是指向数组的指针, 只要修改一个所有都会改变
        dp = [[False for i in range(n + 1)] for j in range(m + 1)]
        dp[0][0] = True
        for j in range(1, n + 1):
            dp[0][j] = j > 1 and dp[0][j - 2] and (p[j - 1] == '*')

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] is not '*':
                    dp[i][j] = dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '.')
                else:
                    dp[i][j] = dp[i][j - 2] or dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.')

        return dp[m][n]




if __name__ == '__main__':
    sol = Solution()
    # false
    print("aa, a",sol.isMatch("aa", "a"))
    # true
    print("aa, .*",sol.isMatch("aa", ".*"))
    # true
    print("aa, a*",sol.isMatch("aa", "a*"))
    # true
    print("ab, .*",sol.isMatch("ab", ".*"))
    # false
    print("aaa, aa",sol.isMatch("aaa", "aa"))
