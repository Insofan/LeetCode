#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/17 9:29 AM
# @Author  : Insomnia
# @Desc    : 股票最大利润
# @File    : BestStock.py
# @Software: PyCharm

import sys
class Solution:
    def bestStock(self, arr):
        if len(arr) == 0:
            return 0
        minPrice = sys.maxsize
        maxPro = -sys.maxsize
        for val in arr:
            minPrice = min(minPrice, val)
            maxPro = max(maxPro, val - minPrice)
        return maxPro
if __name__ == '__main__':
    arr = [9, 11, 8, 5, 7, 12, 16, 14]
    print("stock :")
    print(arr)
    sol = Solution()
    print(sol.bestStock(arr))