#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-11-20 下午11:23
# @Author  : Insomnia
# @Desc    : 前序中序重建二叉树
# @File    : ConstructBinaryTreePreInOrder.py
# @Software: PyCharm

import utils.BinaryTree.BinaryTree


class Solution:
    """
    @param inorder: A list of integers that inorder traversal of a tree
    @param postorder: A list of integers that postorder traversal of a tree
    @return: Root of a tree
    """


    def buildTree(self, preorder, inorder):
        return self.__buildHelper(preorder, 0, len(preorder), inorder, 0, len(inorder))

    def __buildHelper(self, pre, pl, pr, inorder, il, ir):
        if pl >= pr and il >= ir:
            return None
        root_val = pre[pl]
        for i in  range(0, len(inorder)):
            if (inorder[i] == root_val):
                break

        bt = utils.BinaryTree.BinaryTree
        # root = utils.BinaryTree.BinaryTree(root_val)
        root = bt.BinaryTree(root_val)
        left = self.__buildHelper(pre[1:1 + i], inorder[:i])
        right = self.__buildHelper(pre[1 + i:], inorder[i + 1:])
        return root



if __name__ == '__main__':
    pre_order = [1, 2, 3]
    in_order = [2, 1, 3]
    sol = Solution()
    bt = utils.BinaryTree.BinaryTree

    res = sol.buildTree(pre_order, in_order)
    print(res)
