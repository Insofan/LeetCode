#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/16 10:09 AM
# @Author  : Insomnia
# @Desc    : 打印N个骰子, 点数为s的概率
# @File    : DiceSum.py
# @Software: PyCharm


#  python 还无法实现, 详见 cpp版本
class Solution:
    def diceSum(self, n):
        dp = [[0 for j in range(7)] for i in range(6 * n + 1)]

        for j in range(1, 7):
            dp[1][j] = round(1 / 6, 3)


        for i in range(2, n + 1):
            for j in range(i, 6 * n + 1):
                for k in range(6):
                    if (j > k):
                        dp[i][j] += dp[i - 1][j - k]
                        continue

        print(dp)

        return None
if __name__ == '__main__':
    sol = Solution()
    sol.diceSum(5)
