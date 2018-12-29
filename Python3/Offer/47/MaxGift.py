#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/29 9:51 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : MaxGift.py
# @Software: PyCharm

class Solution:
    def maxGift(self, gift):
        row = len(matrix)
        col = len(matrix[0])
        dp = [[0 for i in range(row)] for j in range(col)]
        dp[0][0] = gift[0][0]
        for j in  range(1, col):
            dp[0][j] = dp[0][j - 1] + gift[0][j]
        for i in range(1, row):
            dp[i][0] = dp[i - 1][0] + gift[i][0]

        for i in range(1, row):
            for j in range(1, col):
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]) + gift[i][j]
        return dp[row - 1][col - 1]

if __name__ == '__main__':
    matrix = [
        [1, 10, 3, 8],
        [12, 2, 9, 6],
        [5, 7, 4, 11],
        [3, 7, 16, 5]
    ]
    print(matrix)
    sol = Solution()
    print(sol.maxGift(matrix))