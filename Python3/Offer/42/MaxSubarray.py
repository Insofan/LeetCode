#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/26 10:12 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : MaxSubarray.py
# @Software: PyCharm

class Solution:
    def maxSubarry(self, arr):
        res = 0
        dp = []
        dp.append(arr[0])
        for i in range(1, len(arr)):
            dp.append(max(arr[i], arr[i] + dp[i - 1]))
            if dp[i] > res:
                res = dp[i]
        return res

if __name__ == '__main__':
    arr = [1, -2, 3, 10, -4, 7, 2, -5]
    sol = Solution()
    print(sol.maxSubarry(arr))