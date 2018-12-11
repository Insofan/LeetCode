#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/11 10:06 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : LayerOrderBT.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree

bt = utils.BinaryTree.BinaryTree

class Solution:
    def layOrder(self, root):
        res = []
        self.__orderHelper(root, 0, res)
        return res

    def __orderHelper(self, node, layer, res):
        if not node:
            return None
        if len(res) == layer:
            res.append([])

        res[layer].append(node.val)
        self.__orderHelper(node.left, layer+1, res)
        self.__orderHelper(node.right, layer+1, res)
        return None

if __name__ == '__main__':
    a = bt.BinaryTree(1)
    b = bt.BinaryTree(2)
    c = bt.BinaryTree(3)
    d = bt.BinaryTree(4)
    e = bt.BinaryTree(5)
    f = bt.BinaryTree(6)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f

    sol = Solution()
    print(sol.layOrder(a))
