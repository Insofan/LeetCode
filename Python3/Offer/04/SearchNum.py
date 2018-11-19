
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix:
            return False
        row = len(matrix)
        col = len(matrix[0])
        i = 0
        j = col - 1

        while i < row and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False


if __name__ == '__main__':
    matrix = [
        [1, 2, 3],
        [2, 3, 6],
        [3, 6, 7],
    ]

    sol = Solution()

    res = sol.searchMatrix(matrix, 6)
    print(res)

    res = sol.searchMatrix(matrix, 10)
    print(res)
