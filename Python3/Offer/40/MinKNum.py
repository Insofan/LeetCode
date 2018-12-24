#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/24 9:55 AM
# @Author  : Insomnia
# @Desc    : 最小的k个数
# @File    : MinKNum.py
# @Software: PyCharm
import heapq
class Solution:

    def minKNum(self, arr, k):
        return heapq.nsmallest(k, arr)

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 5, 5, 6, 7, 8]
    sol = Solution()
    print(sol.minKNum(arr, 6))