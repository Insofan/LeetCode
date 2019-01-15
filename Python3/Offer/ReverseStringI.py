#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/15 10:53 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : ReverseStringI.py
# @Software: PyCharm

class Solution:
    def reverseStr(self, str):
        return str[::-1]

if __name__ == '__main__':
    s = "Hello world!"
    sol = Solution()
    print(sol.reverseStr(s))