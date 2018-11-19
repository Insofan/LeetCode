#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/19 12:02 PM
# @Author  : Insomnia
# @Desc    : TODO
# @File    : DuplicateNumII.py
# @Software: PyCharm

class Solution:
    def duplicateNum(self, vec):
        if len(vec) == 0:
            return False
        for i in range(len(vec)):
            while vec[i] != i:
                if vec[vec[i]] == vec[i]:
                    return vec[i]
                else:
                    # vec[vec[i]], vec[i]  = vec[i], vec[vec[i]]
                    vec[vec[i]], vec[i]  = vec[i], vec[vec[i]]

        return False

if __name__ == '__main__':
    sol = Solution()
    arr = [2,3,1,0,2,5,3]
    print(sol.duplicateNum(arr))
    # print(sol.duplicate2(arr))