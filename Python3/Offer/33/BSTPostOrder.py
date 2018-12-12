#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/12 2:32 PM
# @Author  : Insomnia
# @Desc    : 二叉搜索树后续遍历
# @File    : BSTPostOrder.py
# @Software: PyCharm

class Solution:
    def vertifySeqOfBst(self, arr):
        """
        len = 0 或者1的情况 要根据题目来具体设置, 这里暂时设置为 False和true
        :param arr:
        :return:
        """
        if len(arr) == 0:
            return False
        if len(arr) == 1:
            return True

        left = 0
        right = len(arr) - 1
        return self.__helper(arr,left,right)


    def __helper(self, arr,start, end):
        if (start >= end):
            return True

        root = arr[end]

        # 中序遍历 左子树终止位置
        i = 0
        for i in range(start, end):
            if (arr[i] > root):
                break

        j = i

        for j in range(i, end):
            if (arr[j] < root):
                return False

        left = self.__helper(arr, start, i - 1)
        right = self.__helper(arr, i, end - 1)
        return left and right

if __name__ == '__main__':
    arr1 = [5, 7, 6, 9, 11, 10, 8]
    sol = Solution()
    print(sol.vertifySeqOfBst(arr1))
    arr2 = [7, 4, 6, 5]
    sol = Solution()
    print(sol.vertifySeqOfBst(arr2))
