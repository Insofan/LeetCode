#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/12 4:00 PM
# @Author  : Insomnia
# @Desc    : TODO, leetcode 105
# @File    : CopyRandomPointList.py
# @Software: PyCharm
class RandomListNode(object):
    def __init__(self, label, p=None, random=None):
        self.label = label
        self.next = p
        self.random = random


class Solution:
    # def copyRandList(self, head):
    #     dic = dict()
    #     m = n = head
    #     while m:
    #         dic[m] = RandomListNode(m.label)
    #         m = m.next
    #     while n:
    #         dic[n].next = dic.get(n.next)
    #         dic[n].random = dic.get(n.random)
    #         n = n.next
    #     return dic.get(head)
    def copyRandList(self, head):
        arr = []
        dic = dict()
        ptr = head
        i = 0
        while ptr:
            arr.append(RandomListNode(ptr.label))
            dic[ptr] = i
            ptr = ptr.next
            i+=1

        arr.append(None)
        ptr = head
        i = 0
        while ptr:
            arr[i].next = arr[i+1]
            if (ptr.random):
                index = dic.get(ptr.random)
                arr[i].random = arr[index]
            ptr = ptr.next
            i+=1
        return arr[0]


if __name__ == '__main__':
    a = RandomListNode(1)
    b = RandomListNode(3)
    c = RandomListNode(5)

    a.next = b
    b.next = c

    a.random = c
    b.random = a
    c.random = b

    sol = Solution()
    resHead = sol.copyRandList(a)
    res = []
    resRandom = []
    while resHead:
        res.append(resHead.label)
        resRandom.append(resHead.random.label)
        resHead = resHead.next
    print(res)
    print(resRandom)
