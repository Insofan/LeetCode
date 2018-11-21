#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/21 9:32 AM
# @Author  : Insomnia
# @Desc    : 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
# @File    : NextNodeInorder.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree

class ParentBT:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None
        self.parent = None

class Solution:
    def nextNode(self, node):
        if not node:
            return None
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        else:
            # 向上寻找父节点
            par = node.parent
            while not par and par.left != node:
                node = par
                par = par.parent
            return par


if __name__ == '__main__':
    bt = utils.BinaryTree.BinaryTree
    a = ParentBT(1)
    b = ParentBT(2)
    c = ParentBT(3)
    d = ParentBT(4)
    e = ParentBT(5)
    f = ParentBT(6)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f

    # parent
    b.parent = a
    c.parent = a
    d.parent = b
    e.parent = b
    f.parent = c

    print(bt.layerOrder(a))
    sol = Solution()
    node = d
    print(node.val)
    print(sol.nextNode(node).val)
