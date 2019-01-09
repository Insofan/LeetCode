#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/9 10:44 AM
# @Author  : Insomnia
# @Desc    : 统计一个数在排序数组中出现的次数
# @File    : FindCountInSortArr.py
# @Software: PyCharm
# hash表无脑做出

class Solution:
    def countOfNum(self, arr, tar):
        tarIndex = self.__binarySearch(arr, tar)
        # 此时nextTar是4 不存在于数组中
        nextTarIndex = self.__binarySearch(arr, tar+1)
        if (tarIndex <= len(arr) and arr[tarIndex] == tar and nextTarIndex - 1 <= len(arr) and arr[nextTarIndex - 1] == tar):
            return nextTarIndex - tarIndex
        else:
            return  -1

    def __binarySearch(self, arr, tar):
        l = 0
        r = len(arr) - 1

        while l <= r:
            mid = int((r + l ) / 2)
            if (tar > arr[mid]):
                l = mid + 1
            else:
                r = mid -1

        return l

if __name__ == '__main__':
    arr = [1, 2, 3, 3, 3, 3, 5, 6, 6]
    sol = Solution()
    print(sol.countOfNum(arr, 3))
    print(sol.countOfNum(arr, 4))
    print(sol.countOfNum(arr, 6))
