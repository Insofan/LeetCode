#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/23 9:41 AM
# @Author  : Insomnia
# @Desc    : 矩阵中的路径, 同leetcode word search
# @File    : WordSearch.py
# @Software: PyCharm

class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (self.__helper(board, word, i, j, 0)):
                    return True

        return False


    def __helper(self, board, word, i, j, index):
        # 所有index相等
        if index == len(word):
            return True

        if i < 0 or j < 0 or i > (len(board) - 1) or j > (len(board[0]) - 1):
            return False

        if board[i][j] != word[index]:
            return False

        #  将搜索过的内容, 变为 *, 防止重复搜索
        board[i][j] = '*'

        res = self.__helper(board, word, i + 1, j , index + 1) or self.__helper(board, word, i - 1, j, index + 1) or self.__helper(board, word, i, j + 1, index + 1) or self.__helper(board, word, i, j -  1, index + 1)
        board[i][j] = word[index]
        return res



if __name__ == '__main__':
    sol = Solution()
    board = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E'],
    ]
    word = "ABCCED"

    print(sol.exist(board, word))
