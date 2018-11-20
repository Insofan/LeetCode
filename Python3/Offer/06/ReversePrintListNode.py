#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/20 2:11 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : ReversePrintListNode.py
# @Software: PyCharm


import utils.ListNode.ListNode


class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # 逆序链表法
        # tmp = None
        #
        # while head:
        #     next = head.next
        #     head.next = tmp
        #     tmp = head
        #     head = next
        res = []
        while head:
            # res += head.val
            res.append(head.val)
            head = head.next
        res.reverse()
        for val in res:
            print(val, end=' ')

        return None


if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5]
    node = utils.ListNode.ListNode
    head = node.generateListNode(arr)
    print("Original List: ")
    node.printListNode(head)
    print()
    sol = Solution()
    res = sol.reverseList(head)
