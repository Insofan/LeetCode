#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-11-21 下午10:38
# @Author  : Insomnia
# @Desc    : 旋转数组的最小数字
# @File    : RotateMinNum.py
# @Software: PyCharm
class Solution:
    """
    @param nums: a rotated sorted array
    @return: the minimum number in the array
    """
    def findMin(self, nums):
        """
        注意python中的整除使用方法 //
        :param nums: 数组
        :return: 结果
        """
        # write your code here
        l = 0
        r = len(nums) - 1

        while l <  r :

            mid = (l + r) // 2

            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        return nums[l]

if __name__ == '__main__':
    arr = [4, 5, 6, 7, 0, 1, 2]
    sol = Solution()
    print(sol.findMin(arr))
