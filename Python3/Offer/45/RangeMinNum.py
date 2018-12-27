#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/27 10:32 AM
# @Author  : Insomnia
# @Desc    : 把数组排成最小的数字
# @File    : RangeMinNum.py
# @Software: PyCharm

class Solution:
    def rangeMinNum(self, arr):
        num = [str(val) for val in arr]
        num.sort()
        num.reverse()
        res = ''.join((val for val in num))
        print(res)
        return ''.join(res).lstrip('0') or '0'


if __name__ == '__main__':
    print("Hello world!")
    arr = [3, 32, 321]
    sol = Solution()
    print(sol.rangeMinNum(arr))