//
// Created by Insomnia on 2018/10/11.
// 同leetcode 3
//Longest Substring Without Repeating Characters

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int longestNoRepeatingStr(string str) {
        int res = 0;
        set<char> noRepeatSet;

        for (int i = 0; i < str.length(); i++) {
            if (noRepeatSet.count(str[i]) == 0) {
                noRepeatSet.insert(str[i]);
                int size = noRepeatSet.size();
                res = max(res, size);
            } else {
                noRepeatSet.erase(str[i]);
            }
        }
        return res;
    }
};

int main() {

    string   a1 = "abcabcbb";
    string   a2 = "bbbbb";
    string   a3 = "pwwkew";
    string   a4 = "abcdefghijklmn";

    Solution solution;
    cout << solution.longestNoRepeatingStr(a1) << endl;
    cout << solution.longestNoRepeatingStr(a2) << endl;
    cout << solution.longestNoRepeatingStr(a3) << endl;
    cout << a4.length() << endl;
    cout << solution.longestNoRepeatingStr(a4) << endl;

    return 0;
}
