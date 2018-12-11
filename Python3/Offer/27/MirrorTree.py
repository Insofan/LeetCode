#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/7 10:31 AM
# @Author  : Insomnia
# @Desc    : 二叉树的镜像
# @File    : MirrorTree.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree

bt = utils.BinaryTree.BinaryTree

class Solution:
    def mirrorTree(self, root):
        if not root:
            return None
        res = root
        tmp = res.left
        res.left = self.mirrorTree(root.right)
        res.right = self.mirrorTree(tmp)
        return res

if __name__ == '__main__':
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)
    f = bt.BinaryTree(6)
    g = bt.BinaryTree(7)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g
    ori = bt.layerOrder(a)
    print("Origin:")
    print(ori)
    print("Mirror:")
    sol = Solution()
    res = bt.layerOrder(sol.mirrorTree(a))
    print(res)
