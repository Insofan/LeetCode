//
// Created by Insomnia on 2018/7/4.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        /*放结果*/
        vector<vector<string>> result;

        /*存某一次位置*/
        vector<string> location;
        /*攻击位置*/
        vector<vector<int>> mark;

        /*
         * 初始化
         * mark 初始化全部为0
         * location 初始化全部为 '.'
         */
        for (int i = 0; i < n; ++i) {
            mark.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                mark[i].push_back(0);
            }

            location.push_back("");
            location[i].append(n, '.');
        }

        generate(0, n, location, result, mark);
        return result;
    }

private:
    void putDownTheQueen(int x, int y, vector<vector<int>> &mark) {
        /**
         * 方向数组, 用八个数组表示八个方向, 皇后所能达到的区域是这八个方向数组加1
         */
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;

        /*用i 来扩展 n次, j是用来标识8个方向*/
        for (int i = 0; i < mark.size(); ++i) {
            for (int j = 0; j < 8; ++j) {
                int newX = x + i * dx[j];
                int newY = y + i * dy[j];
                if (newX >= 0 && newX < mark.size() && newY >= 0 && newY < mark.size()) {
                    mark[newX][newY] = 1;
                }
            }
        }
    }

    //k代表正在放置第几行 皇后
    void generate(int k, int n, vector<string> &location, vector<vector<string>> &result, vector<vector<int>> &mark) {
        if (k == n) {
            result.push_back(location);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (mark[k][i] == 0) {
                vector<vector<int>> tmpMark = mark;
                location[k][i] = 'Q';
                putDownTheQueen(k, i, mark);
                generate(k + 1, n, location, result, mark);
                //回溯放置之前的状态
                mark = tmpMark;
                location[k][i] = '.';
            }
        }
    }
};

int main() {
    vector<vector<string>> result;
    Solution solution;
    result = solution.solveNQueens(4);
    for (int i = 0; i < result.size(); ++i) {
        cout << "i = " << i <<endl;
        for (int j = 0; j < result[i].size(); ++j) {
           cout << result[i][j].c_str() <<endl;
        }
        cout << endl;
    }
    return 0;
}

