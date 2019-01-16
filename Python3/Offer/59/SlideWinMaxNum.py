#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/16 9:48 AM
# @Author  : Insomnia
# @Desc    : 滑动窗口最大值: 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值, leetcode 经典题目
# @File    : SlideWinMaxNum.py
# @Software: PyCharm

class MonitonicQue:
    def __init__(self):
        self.data = []

    def push(self, x):
        while (len(self.data) > 0 and x > self.data[-1]):
            self.data.pop(-1)
        self.data.append(x)

    def pop(self):
        self.data.pop(0)
    def max(self):
        return self.data[0]

class Solution:
    def slideWinMaxNum(self, arr, width):
        mq = MonitonicQue()
        res = []
        for i in range(0, len(arr)):
            mq.push(arr[i])
            if (i - width + 1 >= 0):
                res.append(mq.max())
                if (arr[i - width + 1] == mq.max()):
                    mq.pop()
        return res

if __name__ == '__main__':
    arr = [2,3,4,2,6,2,5,1]
    print("Slide window max num")
    print("width 3, input:")
    print(arr)
    sol = Solution()
    print("output:")
    print(sol.slideWinMaxNum(arr, 3))
