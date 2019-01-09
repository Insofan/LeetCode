#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/7 9:26 AM
# @Author  : Insomnia
# @Desc    : 逆序对, 此题Python版本有误, 无法ac
# @File    : CountSmallerAfterSelf.py
# @Software: PyCharm

class BSTNode(object):
    def __init__(self, val, small=0, left=None, right=None):
        self.val = val
        self.small = small
        self.left = left
        self.right = right


# 这里python small做参数, 无法使用指针有错误
def insertBSTNode(root, node, small):
    if (node.val < root.val):
        root.small += 1
        if root.left:
            insertBSTNode(root.left, node, small)
        else:
            root.left = node
    else:
        small += root.small + 1
        if root.right:
            insertBSTNode(root.right, node, small)
        else:
            root.right = node

class Solution:
    def countSmaller(self, vec):
        if len(vec) == 0:
            return 0
        res = [0] * len(vec)
        nodeVec = []
        reversed(vec)
        for val in vec:
            nodeVec.append(BSTNode(val))
        res.append(0)

        for i in  range(1, len(vec)):
            res[i] = 0
            insertBSTNode(nodeVec[0], nodeVec[i],res[i])
        reversed(res)
        return res


if __name__ == '__main__':
    arr = [5,2,6,1]
    sol = Solution()
    res = sol.countSmaller(arr)
    print(res)
