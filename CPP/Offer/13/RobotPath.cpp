//
// @ClassName RobotPath
// @Description 机器人运动范围: 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
// @Date 2018/11/23 10:25 AM
// @Created by Insomnia
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int moveCount(int threshold, int rows, int cols) {
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));

        int cnt = robotPath(threshold, rows, cols, 0, 0, visited);

        return cnt;
    }
private:
    int robotPath(int threshold, int row, int col, int curRow, int curCol, vector<vector<bool>> &visited) {
        int res = 0;
        if(check(threshold, row, col, curRow, curCol, visited)) {
            visited[curRow][curCol] = true;

            res = 1 + robotPath(threshold, row, col, curRow + 1, curCol, visited)
                  + robotPath(threshold, row, col, curRow - 1, curCol, visited)
                  + robotPath(threshold, row, col, curRow, curCol + 1, visited)
                  + robotPath(threshold, row, col, curRow, curCol - 1, visited);

        }

        return res;
    }

    bool check(int threshold, int row, int col, int curRow, int curCol, vector<vector<bool>> &visited) {
        if (curRow >= 0 && curRow < row && curCol >= 0 && curCol < col && (visited[curRow][curCol] == false) && getSum(curRow, curCol) <= threshold) {
            return true;
        } else {
            return false;
        }
    }

    int getSum(int num1, int num2) {
        int sum1 = 0;

        while (num1) {
            sum1 += num1 % 10;
            num1 /= 10;
        }
        int sum2 = 0;
        while (num2) {
            sum2 += num2 % 10;
            num2 /= 10;
        }

        return sum1 + sum2;
    }
};

int main() {
    Solution solution;
    cout << solution.moveCount(5, 10, 101) << endl;

    return 0;
}
