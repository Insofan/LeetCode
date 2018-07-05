//
// Created by Insomnia on 2018/7/5.
//
#include <iostream>
#include <vector>

using namespace std;

void putDownTheQueen(int x, int y, vector<vector<int>> &mark) {
    /**
     * 方向数组, 用八个数组表示八个方向, 皇后所能达到的区域是这八个方向数组加1
     */
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    mark[x][y] = 1;

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

int main() {

    return 0;
}
