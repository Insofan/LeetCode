#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-12-5 下午10:52
# @Author  : Insomnia
# @Desc    : TODO
# @File    : MergeKList.py
# @Software: PyCharm
import utils.ListNode.ListNode

listNode = utils.ListNode.ListNode
class Solution:
    def mergeKList(self, listArr):
        if listArr is None:
            return None
        if len(listArr) == 1:
            return listArr[0]
        while (len(listArr) > 1):
            res = self.__mergeTwoList(listArr[0], listArr[1])
            listArr.append(res)
            # 删除两次头元素
            listArr.remove(listArr[0])
            listArr.remove(listArr[0])
        return listArr[0]


    def __mergeTwoList(self, fir, sec):
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
    print("HELLO WORLD")
    arr1 = [1, 3, 5, 7, 9]
    arr2 = [2, 4, 6, 8, 10]
    arr3 = [13, 14, 16, 18, 20]
    arr4 = [22, 24, 26, 28, 30]
    list1 = listNode.generateListNode(arr1)
    list2 = listNode.generateListNode(arr2)
    list3 = listNode.generateListNode(arr3)
    list4 = listNode.generateListNode(arr4)
    arr = [list1, list2, list3, list4]
    sol = Solution()
    listNode.printListNode(sol.mergeKList(arr))