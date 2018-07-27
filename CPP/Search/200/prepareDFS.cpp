//
// Created by Insomnia on 2018/7/27.
//

#include <stdio.h>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y) {

    static const int dx[] = {-1, 0, 1, 0};
    static const int dy[] = {0, -1, 0, 1};

    mark[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX < 0 || newX >= mark.size() || newY < 0 ||newY >= mark[newX].size()) {
            continue;
        }

        if (mark[newX][newY] == 0 && grid[newX][newY] == '1') {
            DFS(mark, grid, newX, newY);
        }
    }
}

int main() {

    return 0;
}
