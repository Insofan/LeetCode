//
// Created by Insomnia on 2018/9/13.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<char>> permutationStr(vector<char> &str) {
        vector<vector<char>> res;
        int          len = str.size();
        vector<char> item;
        helper(0, str,item, res);
        return res;
    }

private:
    void helper(int index, vector<char> &str, vector<char> &item, vector<vector<char>> &res) {

        if (index >= str.size()) {
            return;
        }
        item.push_back(str[index]);
        res.push_back(item);
        helper(index + 1, str, item, res);
        item.pop_back();
        helper(index + 1, str, item, res);
    }
};

int main() {

    string str         = "abc";

    cout << str << endl;
    int len = str.length();
    vector<char> vec;
    for (int i = 0; i < len; ++i) {
        vec.push_back(str[i]);
    }

    for (int i = 0; i < len; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << "--------------" << endl;
//
    Solution       solution;
    vector<vector<char>> res = solution.permutationStr(vec);
    for (int       i   = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
