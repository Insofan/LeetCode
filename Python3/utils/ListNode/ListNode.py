#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/20 2:48 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : ListNode.py
# @Software: PyCharm

class Node(object):
    def __init__(self, val, p = None):
        self.val = val
        self.next = p

def generateListNode(arr):
    if len(arr) == 0:
        return None
    tmp = Node(-1)
    ptr = tmp
    for val in arr:
        ptr.next = Node(val)
        ptr = ptr.next
    return tmp.next

def printListNode(node):
    if node is None:
        return None
    while (node):
        print(node.val, end=' -> ')
        node = node.next
    print('\n')

