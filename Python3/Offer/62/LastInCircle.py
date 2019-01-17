#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/17 9:17 AM
# @Author  : Insomnia
# @Desc    : 约瑟夫环问题, n个人围成环隔m个击毙, 最后剩下
# @File    : LastInCircle.py
# @Software: PyCharm

class Solution:
    def lastInCircle(self, n, m):
        if n < 1 or m < 1:
            return -1
        last = 0
        for i in range(2, n + 1):
            last = (last + m) % i
        return last

if __name__ == '__main__':
    print("5 people 3 gap")
    sol = Solution()
    print(sol.lastInCircle(5, 3))
    print(sol.lastInCircle(12, 3))

