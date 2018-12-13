#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/13 9:59 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : PathSum.py
# @Software: PyCharm
import utils.BinaryTree.BinaryTree

bt = utils.BinaryTree.BinaryTree

class Solution:
    def pathSum(self, root, tar):
        res = []
        path = []
        pathSum = 0
        self.__generate(root, path, pathSum, tar, res)
        return res

    def __generate(self, node, path, pathSum,tar, res):
        if not node:
            return

        pathSum += node.val
        path.append(node.val)

        if (pathSum == tar and  node.left == None and node.right == None):
            # 要浅拷贝, 否则会根据 path变化最后输出为空
            res.append(path.copy())

        self.__generate(node.left, path, pathSum, tar, res)
        self.__generate(node.right, path, pathSum, tar, res)
        pathSum -= node.val
        path.pop()
        return None

if __name__ == '__main__':
    a = bt.BinaryTree(5)
    b = bt.BinaryTree(4)
    c = bt.BinaryTree(8)
    d = bt.BinaryTree(11)
    e = bt.BinaryTree(13)
    f = bt.BinaryTree(4)
    g = bt.BinaryTree(7)
    h = bt.BinaryTree(2)
    i = bt.BinaryTree(5)
    j = bt.BinaryTree(1)
    a.left = b
    a.right = c
    b.left = d
    c.left = e
    c.right =f
    d.left = g
    d.right = h
    f.left = i
    f.right = j
    sol = Solution()
    print(sol.pathSum(a, 22))
