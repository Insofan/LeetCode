#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/16 10:09 AM
# @Author  : Insomnia
# @Desc    : 打印N个骰子, 点数为s的概率
# @File    : DiceSum.py
# @Software: PyCharm


# 这题Python算法有问题, 下面二维数组和 for嵌套,不对
class Solution:
    def diceSum(self, n):
        dp = [[0 for j in range(6*n +1)] for i in range(n+1)]
        print("init: ")
        print(dp)

        for j in range(1, 7):
            dp[1][j] = round(1 / 6, 10)

        res = []

        for i in range(2, n + 1):
            for j in range(i, 6 * n + 1):
                for k in range(6):
                    if (j > k):
                        dp[i][j] += dp[i - 1][j - k]
                dp[i][j] /= 6.0

        for i in range(n, 6 * n + 1):
            res.append((i, dp[n][i]))

        return res
if __name__ == '__main__':
    sol = Solution()
    res = sol.diceSum(5)
    for val in res:
        print(val)

