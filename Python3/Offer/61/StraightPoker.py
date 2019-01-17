#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/17 9:09 AM
# @Author  : Insomnia
# @Desc    : 大小王为任意数, 判断手牌是否为顺子
# @File    : StraightPoker.py
# @Software: PyCharm

class Solution:
    def isStraight(self, arr):
        arr.sort()
        countJoker = 0
        for val in arr:
            if val == 0:
                countJoker+=1

        gap = 0
        for i in range(1, len(arr)):
            if arr[i - 1] == arr[i]:
                return False
            gap += arr[i] - arr[i - 1] - 1

        if (gap >countJoker):
            return False
        else:
            return True

if __name__ == '__main__':
    arr1 = [3, 0, 1, 5, 4]
    print("poker in hand: ")
    print(arr1)
    sol = Solution()
    print(sol.isStraight(arr1))
    arr2 = [3, 0, 1, 6, 4]
    print(arr2)
    print(sol.isStraight(arr2))

