//
// Created by Insomnia on 2018/10/11.
// 同leetcode 64 Minimum Path Sum

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxnumPathNum(vector<vector<int>> grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < col; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < col; j++) {
               dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])+ grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }

};

int main() {
    int a1[] = {1, 10, 3, 8};
    int a2[] = {12, 2, 9, 6};
    int a3[] = {5, 7, 4, 11};
    int a4[] = {3, 7, 16, 5};
    vector<int> vector1(&a1[0], &a1[4]);
    vector<int> vector2(&a2[0], &a2[4]);
    vector<int> vector3(&a3[0], &a3[4]);
    vector<int> vector4(&a4[0], &a4[4]);

    vector<vector<int>> grid;
    grid.push_back(vector1);
    grid.push_back(vector2);
    grid.push_back(vector3);
    grid.push_back(vector4);

    for (int i = 0; i <grid[0].size() ; ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    Solution solution;
    cout << solution.maxnumPathNum(grid) << endl;

    return 0;
}
