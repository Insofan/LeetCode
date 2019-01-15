#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/15 11:21 AM
# @Author  : Insomnia
# @Desc    : 翻转部分字符串例如, abcdefg, 翻转成, defgabc
# @File    : ReverseStringII.py
# @Software: PyCharm

# 此实现方法和c++完全不同
class Solution:
    def reverPartStr(self, str, idx):
        str1 = str[:idx]
        str2 = str[idx:]
        str3 = str2+str1
        return str3
    def __reverseStr(self, str):
        return str[::-1]

if __name__ == '__main__':
    str1 = "abcdefg"
    str2 = "1234567"
    sol = Solution()
    print(sol.reverPartStr(str1, 2))
    print(sol.reverPartStr(str2, 4))
