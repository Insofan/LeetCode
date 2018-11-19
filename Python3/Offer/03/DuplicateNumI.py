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
        map = dict()
        for val in arr:
            if val not in map:
                map[val] = 0
            else:
                return val
        return False


if __name__ == '__main__':
    sol = Solution()
    arr = [2,3,1,0,2,5,3]
    print(sol.duplicateNum(arr))
