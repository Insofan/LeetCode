#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-12 下午8:36
# @Author  : Insomnia
# @Desc    : 判断一个数是否为2的次方, 四个题的blog地址http://www.insomnia.world:30080/2018/10/16/leetcode-136-137-231-260/
# @File    : PowerOfTwo.py
# @Software: PyCharm

class Solution:
    def isTwoPower(self, num):
        fir = num > 0
        sec = not num&(num - 1)
        return  fir and sec
if __name__ == '__main__':
    print("HELLO WORLD")
    sol = Solution()
    print(sol.isTwoPower(4))
    print(sol.isTwoPower(5))
    print(sol.isTwoPower(8))
