#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-11-20 下午11:28
# @Author  : Insomnia
# @Desc    : TODO
# @File    : BinaryTree.py
# @Software: PyCharm

class BinaryTree(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def layerOrder(root):
    if root is None:
        return
    arr = []
    __layerHelper(root, 0, arr)
    return arr

def __layerHelper(root, layer, res):
    if root is None:
        return
    if len(res) == layer:
        res.append([])
    res[layer].append(root.val)
    __layerHelper(root.left, layer + 1, res)
    __layerHelper(root.right, layer + 1, res)