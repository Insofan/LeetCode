#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/15 10:29 AM
# @Author  : Insomnia
# @Desc    : 递增数组中,和为s的数字
# @File    : SumEqS.py
# @Software: PyCharm

class Solution:
    def sumEqS(self, arr, tar):
        dic = dict()
        for val in arr:
            dic[val] = 1

        res = [0] * 2
        # dic[val] = 1 if val not in dic else dic[val] + 1
        for val in arr:
            other = tar - val
            if other in dic:
                if dic[other] > 0:
                    res[0] = val
                    res[1] = other
                    return res
        return None

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    sol = Solution()
    print(sol.sumEqS(arr, 12))
