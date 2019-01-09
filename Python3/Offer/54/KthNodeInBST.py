#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/9 11:12 AM
# @Author  : Insomnia
# @Desc    : 二叉搜索树的K节点
# @File    : KthNodeInBST.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree
bt = utils.BinaryTree.BinaryTree

class Solution:
    def kThInBST(self, root, k):
        res = []
        self.__inorder(root, res)
        if k < len(res):
            return res[k]
        else:
            return None

    def __inorder(self, root, res):
        if not root:
            return
        self.__inorder(root.left, res)
        res.append(root.val)
        self.__inorder(root.right, res)

if __name__ == '__main__':
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)
    f = bt.BinaryTree(6)
    g = bt.BinaryTree(7)

    d.right = f
    f.left = e
    f.right = g

    d.left = b
    b.left = a
    b.right = c

    sol = Solution()
    k = 4
    print(sol.kThInBST(d, k - 1))
    k = 3
    print(sol.kThInBST(d, k - 1))
    k = 7
    print(sol.kThInBST(d, k - 1))
    k = 8
    print(sol.kThInBST(d, k - 1))
