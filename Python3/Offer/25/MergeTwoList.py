#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-5 下午10:19
# @Author  : Insomnia
# @Desc    : 合并两个排序的链表
# @File    : MergeTwoList.py
# @Software: PyCharm

import utils.ListNode.ListNode

listNode = utils.ListNode.ListNode

class Solution:
    def mergeTwoList(self, fir, sec):
        res = listNode.Node(-1)
        ptr = res
        while fir and sec:
            if (fir.val <= sec.val):
                ptr.next = fir
                fir = fir.next
            else:
                ptr.next = sec
                sec = sec.next
            ptr = ptr.next
        if fir:
            ptr.next = fir
        if sec:
            ptr.next = sec
        return res.next

if __name__ == '__main__':
    arr1 = [1, 3, 5, 7, 9]
    arr2 = [2, 4, 6, 8, 10]
    list1 = listNode.generateListNode(arr1)
    list2 = listNode.generateListNode(arr2)
    sol = Solution()
    listNode.printListNode(sol.mergeTwoList(list1, list2))
