#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/21 1:34 PM
# @Author  : Insomnia
# @Desc    : 序列化二叉树
# @File    : SerDecBt.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree

bt = utils.BinaryTree.BinaryTree

class Solution:
    def serBt(self, root):
        def doit(node):
            if node:
                vals.append(str(node.val))
                doit(node.left)
                doit(node.right)
            else:
                vals.append('#')
        vals = []
        doit(root)
        return ' '.join(vals)

    def decBt(self, data):
        def doit():
            val = next(vals)
            if val == '#':
                return None
            node = bt.BinaryTree(int(val))
            node.left = doit()
            node.right = doit()
            return node
        vals = iter(data.split())
        return doit()




if __name__ == '__main__':
    print("Hello world!")
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)

    a.left = b
    a.right = c
    b.left = d
    c.right = e

    sol = Solution()
    print(sol.serBt(a))
    print(sol.decBt(sol.serBt(a)))
