#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/28 1:59 PM
# @Author  : Insomnia
# @Desc    : 剪绳子: 给你一根长度为n的绳子，请把绳子剪成m段 (m和n都是整数，n>1并且m>1)每段绳子的长度记为k[0],k[1],...,k[m].请问k[0]*k[1]*...*k[m]可能的最大乘积是多少？
# @File    : CutRope.py
# @Software: PyCharm

class Solution:
    def cutRope(self, length):
        if (length <= 1):
            return length
        if (length == 2):
            return 1
        if (length == 3):
            return 2

        dp = [0] * (length + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3

        for i in range(4, length + 1):
            myMax = 0
            for j in range(1, i // 2 + 1):
                tmp = dp[j] * dp[i - j]
                myMax = max(myMax, tmp)
            dp[i] = myMax
        return dp[length]


if __name__ == '__main__':
    sol = Solution()
    length = 8
    print(sol.cutRope(length))
