#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/21 3:25 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : PermutationStr.py
# @Software: PyCharm

class Solution:
    def permutationStr(self, str):
        def doit(i, tmp):
            if i >= len(str):
                return
            tmp += str[i]
            res.append(tmp)
            doit(i+1, tmp)
            tmp = tmp[:-1]
            doit(i+1, tmp)

        res = []
        tmp = ""
        doit(0, tmp)
        return res

if __name__ == '__main__':
    print("Hello world!")
    str = "abc"
    sol = Solution()
    print(sol.permutationStr(str))