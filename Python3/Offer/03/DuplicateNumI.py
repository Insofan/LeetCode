#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/19 11:49 AM
# @Author  : Insomnia
# @File    : DuplicateNumI.py
# @Software: PyCharm

class Solution:
    def duplicateNum(self, arr):
        if len(arr) == 0:
           return False
        res = 0
        map = dict()
        for val in arr:
            if val not in map:
                map[val] = 0
            else:
                res = val
                return res
        return False


if __name__ == '__main__':
    sol = Solution()
    arr = [1, 2, 1, 0]
    print(sol.duplicateNum(arr))
