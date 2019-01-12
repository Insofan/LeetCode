#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-12 下午10:39
# @Author  : Insomnia
# @Desc    : 所有数出现两次, 只有一个出现一次
# @File    : SingleNumI.py
# @Software: PyCharm

class Solution:
    def singleNum(self, arr):
        res = 0
        for val in arr:
            res^=val
        return res

if __name__ == '__main__':
    print("HELLO WORLD")
    arr = [1, 1, 2, 2, 3, 5, 5, 6, 6]
    sol = Solution()
    print(sol.singleNum(arr))
