//
// Created by Insomnia on 2018/7/26.
//


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int result = 0;
        string word = "";
        int charMap[128] = {0};

        for (int i = 0; i < s.length(); ++i) {
            charMap[s[i]]++;
            if (charMap[s[i]] == 1) {
                word += s[i];
                if (result < word.length()) {
                    result = word.length();
                }
            } else {
                while (begin < i && charMap[s[i]] > 1) {
                    charMap[s[begin]]--;
                    begin++;
                }
                word = "";

                for (int j = begin; j <= i; ++j) {
                    word += s[j];
                }
            }
        }
        return result;
    }
};

int main() {
    string s = "abcdadab";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);

    return 0;
}
