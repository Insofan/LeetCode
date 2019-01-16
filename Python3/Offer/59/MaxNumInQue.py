#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/16 9:30 AM
# @Author  : Insomnia
# @Desc    : 定义一个队列并实现函数max得到队列里的最大值。要求max，pushBack，popFront的时间复杂度都是o(1)。
# @File    : MaxNumInQue.py
# @Software: PyCharm

# 思路用单调队列

class MonitonicQue:
    def __init__(self):
        self.data = []

    def push(self, x):
        while (len(self.data) > 0 and x > self.data[-1]):
            self.data.pop(-1)
        self.data.append(x)

    def pop(self, x):
        self.data.pop(0)

    def max(self):
        return self.data[0]


class Solution:
    def maxNumInArr(self, arr):
        mq = MonitonicQue()
        for val in arr:
            mq.push(val)
        return mq.max()




if __name__ == '__main__':
    arr = [1, 3, 5, 7, 9, 10, 8, 6, 4, 2]
    sol = Solution()
    print(sol.maxNumInArr(arr))
