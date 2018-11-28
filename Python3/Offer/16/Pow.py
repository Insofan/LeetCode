#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/28 3:00 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : Pow.py
# @Software: PyCharm

class Solution:
    def myPow(self, x, y):
        if y == 0:
            return 1.0
        if (y < 0):
            return  1/x * self.myPow( 1/ x, -(y + 1))
        else:
            return self.myPow(x * x, y / 2) if y % 2 == 0 else x * self.myPow(x*x, y // 2)

if __name__ == '__main__':
    sol = Solution()
    print(sol.myPow(3, 2))
    print(sol.myPow(3, 3))
    print(sol.myPow(5, 2))
