#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 19-1-20 下午10:29
# @Author  : Insomnia
# @Desc    : 二叉树公共祖先
# @File    : LCA.py
# @Software: PyCharm
import utils.BinaryTree.BinaryTree

bt = utils.BinaryTree.BinaryTree


class Solution:
    def lowCommonAncter(self, root, p, q):
        return self.__helper(root, p, q)

    def __helper(self, root, p, q):
        if (root == None or root == p or root == q):
            return root
        p1 = self.__helper(root.left, p, q)
        p2 = self.__helper(root.right, p, q)
        if (p1 and p2):
            return root
        if p1:
            return p1
        else:
            return p2


if __name__ == '__main__':
    sol = Solution()
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)
    f = bt.BinaryTree(6)
    h = bt.BinaryTree(7)
    a.left = b
    a.right = c

    b.left = d
    b.right = e

    c.left = f

    d.left = h

    print("layer order:")
    print(bt.layerOrder(a))
    print(sol.lowCommonAncter(a, f, d).val)


