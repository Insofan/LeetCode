//
// Created by Insomnia on 2018/7/27.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y) {
    static const int dx[] = {-1, 1, 0, 0};
    static const int dy[] = {0, 0, -1, 1};

    queue<pair<int, int>> Q;

    Q.push(make_pair(x, y));
    mark[x][y] = 1;

    while (!Q.empty()) {

        x = Q.front().first;
        y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = dx[i] + x;
            int newY = dy[i] + y;

            if (newX < 0 || newX >= mark.size() || newY < 0 || newY >= mark.size()) {
                continue;
            }

            if (mark[newX][newY] == 0 && grid[newX][newY] == '1') {
                Q.push(make_pair(newX, newY));
                mark[newX][newY] = 1;
            }
        }
    }
}


int main() {

    return 0;
}
