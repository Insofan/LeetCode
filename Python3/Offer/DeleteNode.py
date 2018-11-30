#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/30 10:39 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : DeleteNode.py
# @Software: PyCharm


import utils.ListNode.ListNode

listNode = utils.ListNode.ListNode


class Solution:
    def deleteNode(self, head, tar):
        preHead = listNode.Node(-1)
        preHead.next = head
        ptr = preHead

        while (ptr):
            if (ptr.next and ptr.next.val == tar):
                ptr.next = ptr.next.next
            else:
                ptr = ptr.next
        return preHead.next

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5]
    headNode = listNode.generateListNode(arr)
    print("Origin:")
    listNode.printListNode(headNode)
    sol = Solution()
    print("Deleted 3:")
    res =sol.deleteNode(headNode, 3)
    listNode.printListNode(res)
    print("Deleted 5:")
    res =sol.deleteNode(headNode, 5)
    listNode.printListNode(res)
    print("Deleted 1:")
    res = sol.deleteNode(headNode, 1)
    listNode.printListNode(res)

