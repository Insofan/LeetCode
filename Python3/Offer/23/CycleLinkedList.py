#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-5 下午9:21
# @Author  : Insomnia
# @Desc    : 链表中环的入口节点
# @File    : CycleLinkedList.py
# @Software: PyCharm
import utils.ListNode.ListNode

listNode = utils.ListNode.ListNode

class Solution:
    def linkedNode(self, head):
        res = None
        meet = None
        fast = head
        slow = head

        while (fast):
            slow = slow.next
            fast = fast.next
            if (fast == None):
               return None
            fast = fast.next
            if (fast == slow):
                meet = fast
                break

        while (head):
            if (meet == head):
                return meet
            head = head.next
            meet = meet.next

        return None

if __name__ == '__main__':
    sol = Solution()
    a = listNode.Node(1)
    b = listNode.Node(2)
    c = listNode.Node(3)
    d = listNode.Node(4)
    e = listNode.Node(5)
    f = listNode.Node(6)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    f.next = c
    print(sol.linkedNode(a).val)