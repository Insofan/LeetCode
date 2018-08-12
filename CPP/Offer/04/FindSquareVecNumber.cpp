// 
// Created by Insomnia on 18-8-12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findSquareVecNum(vector<vector<int>> &vec, int target) {

        if (vec.size() == 0) {
            return  -1;
        }

        int row = vec.size() ;
        int col = vec[0].size();

        bool res = false;
        for (int i = 0, j = col - 1; (i < row && j >= 0) && (j < col && j >= 0);) {
            if ( target == vec[i][j]) {
                res = true;
                break;
            } else if ( target < vec[i][j]) {
                j--;
            } else{
                i++;
            }
        }

        return res;
    }
};


int main () {
    int nums[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    vector<vector<int>> vec;
    for (int i = 0; i < 4; ++i) {
        vec.push_back(vector<int>());
        for (int j = 0; j < 4; ++j) {
            vec[i].push_back(nums[i][j]);
        }
    }

   Solution solution;
    cout <<  boolalpha << solution.findSquareVecNum(vec, 11) << endl;

    return  0;
}