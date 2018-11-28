#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/27 5:23 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : RobotPath.py
# @Software: PyCharm

class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        mark = [[False] * rows] * cols
        res = self.generate(threshold, 0, rows, 0, cols, mark)
        return res

    def generate(self, threshold, row, rows, col, cols, mark):
        res = 0
        if (self.check(threshold, row, rows, col, cols, mark)):
            mark[row][col] = True
            res = 1 + self.generate(threshold, row + 1, rows, col, cols, mark) + self.generate(threshold, row - 1, rows,
                                                                                               col, cols,
                                                                                               mark) + self.generate(
                threshold, row, rows, col + 1, cols, mark) + self.generate(threshold, row, rows, col - 1, cols, mark)
        return res

    def check(self, threshold, row, rows, col, cols, mark):
        if (row >= 0 and row < rows and col >= 0 and col < cols and (self.getSum(row, col) <= threshold) and (mark[row][col] == False)):
            return True
        else:
            return False

    def getSum(self, x, y):
        res = 0
        while (x):
            res += x % 10
            x /= 10

        while (y):
            res += y % 10
            y /= 10
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.movingCount(4, 10 , 15))
