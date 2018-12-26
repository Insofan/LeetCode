#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/26 10:40 AM
# @Author  : Insomnia
# @Desc    : 数字1出现次数, 算术题
# @File    : NumOfDigitOne.py
# @Software: PyCharm

class Solution:
    def numOfDigit(self, num):
        res = 0
        m = 1
        while m <= num:
            res += (num / m + 8) / 10 * m + (num / m %10  == 1) * (num % m + 1)
            m *= 10
        return res

if __name__ == '__main__':
    print("Hello world!")
    sol = Solution()
    # 20
    print(sol.numOfDigit(99))
    # 20 + 120
    print(sol.numOfDigit(199))
    # 9*20 + 120
    print(sol.numOfDigit(999))
