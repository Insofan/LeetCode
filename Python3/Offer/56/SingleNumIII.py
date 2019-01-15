#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/15 10:05 AM
# @Author  : Insomnia
# @Desc    : 求数组中两个出现一次的数, 其他数出现两次
# @File    : SingleNumIII.py
# @Software: PyCharm

class Solution:
    def singleNum(self, arr):
        xval = 0
        for val in arr:
            xval ^= val

        xval ^= xval & (xval - 1)

        res = [0] * 2
        for val in arr:
            if (xval & val) > 0:
                res[0] ^= val
            else:
                res[1] ^= val

        return res

if __name__ == '__main__':
    arr = [1, 1, 2, 2, 3, 5, 5, 6]
    sol = Solution()
    print(sol.singleNum(arr))
