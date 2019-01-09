#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/9 11:39 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : DepthOfBT.py
# @Software: PyCharm
import utils.BinaryTree.BinaryTree
bt = utils.BinaryTree.BinaryTree

class Solution:
    def depthOfBT(self, node):
        if not node:
            return 0
        else:
            ld = self.depthOfBT(node.left)
            rd = self.depthOfBT(node.right)
            return 1 + max(ld, rd)


if __name__ == '__main__':
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)
    f = bt.BinaryTree(6)
    g = bt.BinaryTree(7)
    # h = bt.BinaryTree(8)

    d.right = f
    f.left = e
    f.right = g
    # g.right = h

    d.left = b
    b.left = a
    b.right = c

    sol = Solution()
    print(sol.depthOfBT(d))
