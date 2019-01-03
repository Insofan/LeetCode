#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/3 10:13 AM
# @Author  : Insomnia
# @Desc    : 丑数
# @File    : UglyNum.py
# @Software: PyCharm

class Solution:
    def uglyNum(self, num):
        if num == 0:
            return False
        for i in range(2, 6):
            while (num % i == 0):
                num /= i
        return num == 1

if __name__ == '__main__':
    print("Hello world!")
    sol = Solution()
    print(sol.uglyNum(0))
    print(sol.uglyNum(6))
    print(sol.uglyNum(14))
