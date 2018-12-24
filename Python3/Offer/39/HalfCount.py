#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/24 9:30 AM
# @Author  : Insomnia
# @Desc    : 数组中出现次数超过一半的数字
# @File    : HalfCount.py
# @Software: PyCharm

class Solution:
    def halfCount(self, arr):
        dic = dict()
        for val in arr:
            dic[val] = 1 if val not in dic else dic[val] + 1
            if (dic[val] > len(arr) / 2):
                return val
        return None

if __name__ == '__main__':
    print("Hello world!")
    arr = [1, 2, 3, 4, 5,  2, 2, 2, 2]

    sol = Solution()
    sol.halfCount(arr)

