#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-20 下午9:45
# @Author  : Insomnia
# @Desc    : 构建一个数组,数组每一位是除自己以外其他数字的乘积
# @File    : ProductOfArrExceptSelf.py
# @Software: PyCharm

class Solution:
    def exceptSelf(self, arr):
        fromBegin  = 1
        fromEnd = 1
        res = [1] * len(arr)
        for i in range(0, len(arr)):
            res[i] *= fromBegin
            fromBegin *= arr[i]
        for i in range(len(arr) - 1, -1, -1):
            res[i] *= fromEnd
            fromEnd *= arr[i]
        return res

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5]
    sol = Solution()
    print(sol.exceptSelf(arr))