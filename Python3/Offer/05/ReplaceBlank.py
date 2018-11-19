#!/usr/bin/env python

class Solution:
    def replaceBlank(self, str):
        print(str)
        res = ''

        for char in str:
            if char == ' ':
                res += '%20'
            else:
                res += char

        return res


if __name__ == '__main__':
    str = "Hello Python World!"
    sol = Solution()
    print(sol.replaceBlank(str))
