#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/1/9 9:27 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : FirstInjectNode.py
# @Software: PyCharm
import utils.ListNode.ListNode
ln = utils.ListNode.ListNode

class Solution:
    def injectNode1(self, node1, node2):
        hashMap = dict()
        while node1:
            if node1 not in hashMap:
                hashMap[node1] = 1
            else:
                hashMap[node1] += 1
            node1 = node1.next

        while node2:
            if node2 in hashMap:
                return node2
            node2 = node2.next
        return None

    def injectNode2(self, node1, node2):
        """
        将链表1的结尾连接到链表2的结尾, 然后转化为求一个链表是否有环, 并求出环的节点
        :param node1:
        :param node2:
        :return:
        """
        lastNode = None
        tmpNode = node1
        while tmpNode:
            if not tmpNode.next:
                lastNode = tmpNode
            tmpNode = tmpNode.next

        lastNode.next = node2

        return self.__linkedNode(node1)

    def __linkedNode(self, node):

        fast = node
        slow = node
        meet = None

        while fast:
            fast = fast.next
            slow = slow.next
            if not fast:
                return None
            fast = fast.next
            if fast == slow:
                meet = fast
                break

        while node:
            if node == meet:
                return meet
            node = node.next
            meet = meet.next

        return None

if __name__ == '__main__':
    a1 = ln.Node(1)
    b1 = ln.Node(2)
    c = ln.Node(3)
    d1 = ln.Node(4)
    e1 = ln.Node(5)

    a1.next = b1
    b1.next = c
    c.next = d1
    d1.next = e1

    a2 = ln.Node(11)
    b2 = ln.Node(12)
    d2 = ln.Node(14)
    e2 = ln.Node(15)

    a2.next = b2
    b2.next = c
    c.next = d2
    d2.next = e2

    sol = Solution()
    print(sol.injectNode1(a1, a2).val)
    print(sol.injectNode2(a1, a2).val)

