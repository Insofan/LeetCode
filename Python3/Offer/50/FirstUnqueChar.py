#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/7 9:17 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : FirstUnqueChar.py
# @Software: PyCharm

class Solution:
    def firstUniChar(self, str):
        hashMap = dict()
        for ch in str:
            if ch not in hashMap:
                hashMap[ch] = 1
            else:
                hashMap[ch] += 1

        for ch in str:
            if hashMap[ch] == 1:
                return ch
        return None

if __name__ == '__main__':
    str = "abaccdeff"
    sol = Solution()
    print(sol.firstUniChar(str))
