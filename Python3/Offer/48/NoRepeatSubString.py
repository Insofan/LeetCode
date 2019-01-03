#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/3 9:19 AM
# @Author  : Insomnia
# @Desc    : 同leetcode 003
# @File    : NoRepeatSubString.py
# @Software: PyCharm

class Solution:
    def noRepeatSubstring(self, str):
        cSet = set()
        j = 0
        res = 0
        # 这里会报错,结果不对, python 现在 无法像 cpp一样写for循环里面双参数i, j
        for i, j in range(0, len(str)):
            if str[i] not in cSet:
                cSet.add(str[i])
                i+=1
            else:
                if str[j] not in cSet:
                    continue
                cSet.remove(str[j])
                j+=1
            res = max(res, len(cSet))
        return res

if __name__ == '__main__':
    sol = Solution()
    str1 = 'abcabcbb'
    print(sol.noRepeatSubstring(str1))
    str2 = "aab"
    print(sol.noRepeatSubstring(str2))
