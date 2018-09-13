//
// Created by Insomnia on 2018/9/13.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutationNum(vector<int> vec) {

        vector<vector<int>> res;
        vector<int>         tempVec;
        helper(0, vec, tempVec, res);
        return res;
    }

private:
    void helper(int i, vector<int> &vec, vector<int> &tempVec, vector<vector<int>> &res) {
        if (i >= vec.size()) {
            return;
        }

        tempVec.push_back(vec[i]);

        //全排列
        res.push_back(tempVec);
//        if (tempVec.size() == 3) {
//
//            res.push_back(tempVec);
//        }

        helper(i + 1, vec, tempVec, res);
        tempVec.pop_back();
        helper(i + 1, vec, tempVec, res);

    }
};


int main() {
    int         a[5]        = {1, 2, 3, 4, 5};
    vector<int> vec(&a[0], &a[5]);
    for (int    i           = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    Solution            solution;
    vector<vector<int>> res = solution.permutationNum(vec);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
           cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
