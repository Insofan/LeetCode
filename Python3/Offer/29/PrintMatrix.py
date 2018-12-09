#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-9 下午1:46
# @Author  : Insomnia
# @Desc    : 顺时针打印矩阵
# @File    : PrintMatrix.py
# @Software: PyCharm

class Solution:
    def printMatrix(self, matrix):
        rowBegin = 0
        rowEnd = len(matrix)-1
        colBegin = 0
        colEnd = len(matrix[0]) - 1

        res = []
        while (rowBegin <= rowEnd and colBegin <= colEnd):
            for i in range(colBegin, colEnd+1):
                res.append(matrix[rowBegin][i])
            rowBegin+=1

            for i in range(rowBegin, rowEnd+1):
                res.append(matrix[i][colEnd])
            colEnd-=1

            if (rowBegin <= rowEnd):
                for i in range(colEnd, colBegin-1, -1):
                    res.append(matrix[rowEnd][i])
                rowEnd-=1
            if (colBegin <= colEnd):
                for i in range(rowEnd, rowBegin-1, -1):
                    res.append(matrix[i][colBegin])
                colBegin+=1
        return res

if __name__ == '__main__':
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [6, 7, 8, 9, 10]
    arr3 = [11, 12, 13, 14, 15]

    matrix = []
    matrix.append(arr1)
    matrix.append(arr2)
    matrix.append(arr3)

    sol = Solution()
    print(sol.printMatrix(matrix))

