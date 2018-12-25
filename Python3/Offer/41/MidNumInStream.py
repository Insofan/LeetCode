#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/25 10:00 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : MidNumInStream.py
# @Software: PyCharm

import heapq

class Solution:
    def midNumInStrea(self, arr):
        minHeap = []
        maxHeap = []

        return None

if __name__ == '__main__':
    print("Hello world!")
    arr1 = [1, 2, 3, 4, 5, 6]
    arr2 = [1, 2, 3, 4, 6]
    arr3 = [1, 2, 3, 4, 5, 6, 7, 8]
    sol = Solution()
    print("arr1 mid: ",sol.midNumInStrea(arr1))
    print("arr2 mid: ",sol.midNumInStrea(arr2))
    print("arr3 mid: ",sol.midNumInStrea(arr3))
