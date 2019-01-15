#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/15 10:15 AM
# @Author  : Insomnia
# @Desc    : 数字二进制表示种的1的个数
# @File    : CountOfBit.py
# @Software: PyCharm

class Solution:
    def countOfBits(self, num):
        res = 0
        while (num):
            num &= (num - 1)
            res += 1
        return res

if __name__ == '__main__':
    print("Hello world!")
    sol = Solution()
    print(sol.countOfBits(0))
    print(sol.countOfBits(2))
    print(sol.countOfBits(8))
    print(sol.countOfBits(5))
    print(sol.countOfBits(7))
