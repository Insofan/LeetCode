#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/11 9:42 AM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : StackPushPopArr.py
# @Software: PyCharm

class Solution:
    def pushAndPopOrder(self, pushArr, popArr):
        s = []
        index = 0
        for val in pushArr:
            s.append(val)

            while len(s) > 0 and s[-1] == popArr[index]:
                s.remove(s[-1])
                index+=1
        return len(s) == 0

if __name__ == '__main__':
    pushArr = [1, 2, 3, 4, 5]
    popArr1 = [4, 5, 3, 2, 1]
    popArr2 = [4, 3, 5, 1, 2]
    sol = Solution()
    print(sol.pushAndPopOrder(pushArr, popArr1))
    print(sol.pushAndPopOrder(pushArr, popArr2))
