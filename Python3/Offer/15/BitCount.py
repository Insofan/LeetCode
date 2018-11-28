#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/28 2:57 PM
# @Author  : Insomnia
# @Desc    : 一个数二进制种1的个数
# @File    : BitCount.py
# @Software: PyCharm

class Solution:
    def bitcount(self, num):
        res = 0
        while(num):
            num &= num - 1
            res+=1
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.bitcount(7))
    print(sol.bitcount(5))
    print(sol.bitcount(8))
