#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-20 下午9:27
# @Author  : Insomnia
# @Desc    : 不用加减法做加法
# @File    : IntegerSum.py
# @Software: PyCharm

class Solution:
    def sumOfInt(self, a, b):
        if b == 0:
            return a
        else:
            # 第一部分, 不考虑进位的相加. 第二部分, 考虑进位的与运算, 然后向左移一位, 然后递归
            sum = self.sumOfInt(a ^ b, (a&b)<<1)
            return sum

if __name__ == '__main__':
    print("不用加减法做加法")
    print("2 + 3:")
    sol = Solution()
    print(sol.sumOfInt(2, 3))
