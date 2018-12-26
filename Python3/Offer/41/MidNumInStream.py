#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/25 10:00 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : MidNumInStream.py
# @Software: PyCharm

import heapq


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.leftQ = []
        # python 不支持最大堆, 需要将 val的相反数push进去, 从最大堆取的时候也取相反数
        self.rightQ = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        if (len(self.rightQ) == 0):
            heapq.heappush(self.rightQ, -num)
        elif (len(self.rightQ) > len(self.leftQ)):
            if (num < -self.rightQ[0]):
                heapq.heappush(self.leftQ, -self.rightQ[0])
                # 需要用和这个 pop 而不是直接 self.rightQ.pop()
                heapq.heappop(self.rightQ)
                heapq.heappush(self.rightQ, -num)
            else:
                heapq.heappush(self.leftQ, num)
        elif (len(self.leftQ) > len(self.rightQ)):
            if (num < self.leftQ[0]):
                heapq.heappush(self.rightQ, -num)
            else:
                heapq.heappush(self.rightQ, -self.leftQ[0])
                heapq.heappop(self.leftQ)
                heapq.heappush(self.leftQ, num)
        else:
            if (num < -self.rightQ[0]):
                heapq.heappush(self.rightQ, -num)
            else:
                heapq.heappush(self.leftQ, num)

    def findMedian(self):
        """
        :rtype: float
        """
        size = len(self.leftQ) + len(self.rightQ)
        if (size % 2 == 0):
            return (self.leftQ[0] - self.rightQ[0]) / 2.0
        else:
            if len(self.leftQ) > len(self.rightQ):
                return self.leftQ[0]
            else:
                return -self.rightQ[0]


if __name__ == '__main__':
    print("Hello world!")
    med = MedianFinder()
    med.addNum(1)
    # 1
    print("arr1 mid: ",med.findMedian())
    med.addNum(2)
    # 1.5
    print("arr2 mid: ",med.findMedian())
    med.addNum(3)
    # 2
    print("arr3 mid: ",med.findMedian())
    med.addNum(4)
    # 2.5
    print("arr4 mid: ", med.findMedian())
    med.addNum(5)
    # 3
    print("arr5 mid: ", med.findMedian())
