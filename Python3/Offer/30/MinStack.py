#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-9 下午2:34
# @Author  : Insomnia
# @Desc    : 包含min的栈
# @File    : MinStack.py
# @Software: PyCharm

class Solution:
    tmp = []
    data = []
    def pop(self):
        self.tmp.pop()
        self.data.pop()

    def push(self, val):
        if (len(self.data) == 0):
            self.tmp.append(val)
            self.data.append(val)
        else:
            if val <= self.tmp[-1]:
                self.tmp.append(val)
            else:
                self.tmp.append(self.tmp[-1])
            self.data.append(val)

    def min(self):
        return self.tmp[-1]

if __name__ == '__main__':
    arr = [1, 2, 3, 0, 4, 5]
    sol = Solution()
    for val in arr:
        sol.push(val)
    print(sol.min())
    sol.pop()
    print(sol.min())
    sol.pop()
    print(sol.min())
    sol.pop()
    print(sol.min())
    sol.pop()
    print(sol.min())
