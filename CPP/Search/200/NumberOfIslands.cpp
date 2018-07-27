//
// Created by Insomnia on 2018/7/27.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int islandNum = 0;
        vector<vector<int>> mark;

        for (int i = 0; i < grid.size(); ++i) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); ++j) {
                mark[i].push_back(0);
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (mark[i][j] == 0 && grid[i][j] == '1') {
                    BFS(mark, grid, i, j);
                    islandNum++;
                }
            }
        }

        return islandNum;
    }

private:

    void BFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y) {
        static const int dx[] = {-1, 0, 1, 0};
        static const int dy[] = {0, -1, 0, 1};

        queue<pair<int, int >> dQueue;
        dQueue.push(make_pair(x, y));

        mark[x][y] = 1;

        while (!dQueue.empty()) {
            x = dQueue.front().first;
            y = dQueue.front().second;
            dQueue.pop();

            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX < 0 || newX >= mark.size() || newY < 0 || newY >= mark[newX].size()) {
                    continue;
                }

                if (mark[newX][newY] == 0 && grid[newX][newY] == '1') {
                    dQueue.push(make_pair(newX, newY));
                    mark[newX][newY] = 1;
                }
            }
        }

    }
};

int main() {
    vector<vector<char>> grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};

    for (int i = 0; i < 4; ++i) {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5; ++j) {
            grid[i].push_back(str[i][j]);
        }
    }

    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}
