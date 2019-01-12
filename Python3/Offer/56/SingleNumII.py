#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-12 下午10:48
# @Author  : Insomnia
# @Desc    : 所有数字出现三次, 只有一个出现一次
# @File    : SingleNumII.py
# @Software: PyCharm

class Solution:
    def singleNumWithTriple(self, arr):
        fir = 0
        sec = 0
        for val in arr:
            tmp = fir
            fir = (fir&~sec&~val) | (~fir&sec&val)
            sec = (~tmp&sec&~val)  | (~tmp&~sec&val)
        return fir | sec
if __name__ == '__main__':
    arr = [1, 1, 1, 2, 3, 3, 3]
    sol = Solution()
    print(sol.singleNumWithTriple(arr))
