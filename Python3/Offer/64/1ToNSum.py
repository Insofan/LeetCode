#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-20 下午6:54
# @Author  : Insomnia
# @Desc    : 不用条件循环语句, 乘法公式求1到n的和
# @File    : 1ToNSum.py
# @Software: PyCharm

# python 跑不通, 看cpp版本
class Solution:
    def sum(self, n):
        sum = n
        if sum > 0:
            sum += self.sum(n - 1)
        else:
            return sum
if __name__ == '__main__':
    print("1 to n sum")
    print("1 to 100 sum:")
    sol = Solution()
    print(sol.sum(100))
