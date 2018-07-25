//
// Created by Insomnia on 2018/7/25.
//

//注意这个回文 跟 马拉车回文不一样, 马拉车是拥有的subString回文, 而这个是用现有字符串重新排列生成新的
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int charMap[128] = {0};
        int maxLength = 0;
        int flag = 0; //是否有中心点

        for (int i = 0; i < s.length(); ++i) {
            charMap[s[i]]++;
        }

        for (int j = 0; j < 128; ++j) {
           if (charMap[j] % 2 == 0) {

               maxLength += charMap[j];
           }  else {
               maxLength += charMap[j] - 1;
               flag = 1;
           }
        }

        return  maxLength +flag;
    }
};

int main() {
    string s = "abccccddaa";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}
