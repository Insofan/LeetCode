#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/21 4:24 PM
# @Author  : Insomnia
# @Desc    : 用两个栈实现队列
# @File    : QueueUsingStack.py
# @Software: PyCharm


class Solution:
    def __init__(self):
        self.__data= []
        self.__tmp = []


    def push(self, val):
        """
        pycharm 的函数自动注释 是三个引号
        :param val:
        :return:
        """
        if len(self.__data) == 0:
            self.__data.append(val)
        else:
            while self.__data:
                self.__tmp.append(self.__data[-1])
                self.__data.pop()

            self.__data.append(val)

            while self.__tmp:
                self.__data.append(self.__tmp[-1])
                self.__tmp.pop()
        return


    def pop(self):
        if self.__data:
            self.__data.pop()

    def front(self):
        if self.__data:
            return self.__data[-1]
        else:
            return None

if __name__ == '__main__':
    arr = [1, 2, 3]
    sol = Solution()
    for val in arr:
        sol.push(val)
    print(sol.front())
    sol.pop()
    print(sol.front())
    sol.pop()
    print(sol.front())
    sol.pop()
    print(sol.front())
    sol.pop()
    print(sol.front())


