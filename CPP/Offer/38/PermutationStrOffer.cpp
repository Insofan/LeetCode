//
// Created by Insomnia on 2018/9/13.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//全组合
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

//全排列, len 等于原 str, newcoder 字符串的排列ac代码
class Solution2 {
public:
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.length() == 0) {
            return res;
        }
        helper(0, str, res);
        sort(res.begin(), res.end());
        return res;
    }

private:
    void helper(int begin, string &str, vector<string> &res) {
        if (begin >= str.length()) {
            res.push_back(str);
            return;
        }

        for (int i = begin; i < str.length(); i++) {
            // 这一行是在有重复字符时加的判断, 如果无重复可以不加
            if (i == begin || str[i] != str[begin]) {
                swap(str[begin], str[i]);
                helper(begin + 1, str, res);
                swap(str[begin], str[i]);
            }
        }
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
    cout << "------全组合--------" << endl;
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
