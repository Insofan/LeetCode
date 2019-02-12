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

        //全组合
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


class Solution2 {
public:
    vector<vector<int>> permutationNum(vector<int> vec) {

        vector<vector<int>> res;
        helper(0, vec, res);
        return res;
    }

private:
    void helper(int begin,vector<int> &vec, vector<vector<int>> &res) {
        if (begin >= vec.size()) {
            res.push_back(vec);
            return;
        }

        for (int i = begin; i < vec.size(); i++) {
            if (i == begin || vec[i] != vec[begin]) {
                swap(vec[begin], vec[i]);
                helper(begin + 1, vec, res);
                swap(vec[begin], vec[i]);
            }
        }
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

    Solution2 solution2;
    vec.pop_back();
    vec.pop_back();
    vector<vector<int>> res2 = solution2.permutationNum(vec);
    for (int i = 0; i < res2.size(); ++i) {
        for (int j = 0; j < res2[i].size(); ++j) {
           cout << res2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
