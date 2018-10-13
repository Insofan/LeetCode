// 
// Created by Insomnia on 18-10-13.
//同leetcode 387
//First Unique Character in a String

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        map<char, int> hashMap;
        for (int i = 0; i < s.length(); i++) {
            hashMap[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (hashMap[s[i]] == 1) {
                return s[i];
            }
        }
        return -1;
    }
};
int main() {
    string str = "abaccdeff";

    Solution solution;
    cout << solution.firstUniqChar(str) << endl;
    return 0;
}