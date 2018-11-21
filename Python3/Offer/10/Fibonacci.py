#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-11-21 下午10:33
# @Author  : Insomnia
# @Desc    : TODO
# @File    : Fibonacci.py
# @Software: PyCharm

class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """

    def fibonacci(self, n):
        # write your code here
        if n < 3:
            return n - 1;

        res = [0] * n
        res[0] = 0
        res[1] = 1

        for i in range(2, n):
            res[i] = res[i - 1] + res[i - 2]

        return res[i]

if __name__ == '__main__':

    sol = Solution()
    print(sol.fibonacci(8))
