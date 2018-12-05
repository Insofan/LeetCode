#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-5 下午11:17
# @Author  : Insomnia
# @Desc    : TODO
# @File    : SubTree.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree
bt = utils.BinaryTree.BinaryTree

class Solution:
    """
    @param s: the s' root
    @param t: the t' root
    @return: whether tree t has exactly the same structure and node values with a subtree of s
    """
    def isSubtree(self, s, t):
        # Write your code here
        if not s:
            return False
        if (self.isSame(s, t)):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def isSame(self, fir, sec):
        if (not fir or not sec):
            return fir == sec
        else:
            return (fir.val == sec.val) and self.isSame(fir.left, sec.left) and self.isSame(fir.right, sec.right)

if __name__ == '__main__':
    print("HELLO WORLD")
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)

    a.left = b
    a.right = c
    c.left = d
    c.right = e

    c1 = bt.BinaryTree(3)
    d1 = bt.BinaryTree(3)
    e1 = bt.BinaryTree(3)
    c1.left = d1
    c1.right = e1

    sol = Solution()
    print(sol.isSubtree(a, c))
    print(sol.isSubtree(a, c1))
