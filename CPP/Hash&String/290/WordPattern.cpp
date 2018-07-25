//
// Created by Insomnia on 2018/7/25.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> wordMap; //单词到pattern 的映射
        char used[128] = {0};  //已被映射的pattern 字符

        string word;//临时保存拆分的单词

        int pos= 0;
        str.push_back(' ');//遇到空格拆分单词

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {//遇到空格拆分单词
               if (pos == pattern.length()) {
                   return false;//已经没有pattern对应了
               }

               if (wordMap.find(word) == wordMap.end()) {//未找到
                  if (used[pattern[pos]]) {
                      return false;
                  }
                  wordMap[word] = pattern[pos];
                  used[pattern[pos]] += 1;
               } else {
                   if (wordMap[word] != pattern[pos]) {//弱当前word建立映射无法与当前pattern对应
                       return false;
                   }
               }

               word = "";
               pos++;
            } else {
                word += str[i];
            }
        }

        if (pos != pattern.length()) {
            return false;//有多余的pattern
        }

        return true;
    }
};

int main() {
    string pattern = "abba";
//    string pattern = "aabb";
    string str = "apple dog dog apple";

    Solution sol;
    cout << boolalpha << sol.wordPattern(pattern, str) << endl;

    return 0;
}
