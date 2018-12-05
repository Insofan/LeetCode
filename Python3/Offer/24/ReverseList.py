#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-5 下午9:53
# @Author  : Insomnia
# @Desc    : 反转链表
# @File    : ReverseList.py
# @Software: PyCharm

import utils.ListNode.ListNode
import sys

listNode = utils.ListNode.ListNode

class Solution:
    def revListNode1(self, head):
        preHead = listNode.Node(sys.maxsize)
        while (head):
            next = head.next
            head.next = preHead.next
            preHead.next = head
            head = next
        return preHead.next

    def revListNode2(self, head):
        tmp = None
        while head:
            next = head.next
            head.next = tmp
            tmp = head
            head = next
        return tmp

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5]
    head1 =  listNode.generateListNode(arr)
    listNode.printListNode(head1)
    sol = Solution()
    print("Reverse 1: ")
    listNode.printListNode(sol.revListNode1(head1))
    arr2 = [1, 2, 3, 4, 5]
    head2 =  listNode.generateListNode(arr2)
    print("Reverse 2: ")
    listNode.printListNode(sol.revListNode2(head2))

