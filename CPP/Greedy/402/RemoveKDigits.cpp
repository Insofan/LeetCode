//
// Created by Insomnia on 2018/6/28.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;
        string result = "";
        for (int i = 0; i < num.length(); ++i) {
            int number = num[i] - '0';
            /*当栈不空时， 且栈顶元素大雨number， 荏苒可以删除数字时， while 继续*/
            while (S.size() != 0 && S[S.size() - 1] > number && k > 0) {
                S.pop_back();
                k--;
            }
            /*将number 压入栈中*/
            if (number != 0 || S.size() != 0) {
                S.push_back(number);
            }
        }

        while (S.size() != 0 && k >0) {
           S.pop_back();
           k--;
        }

        for (int j = 0; j < S.size(); ++j) {
           result.append(1, '0' + S[j]);
        }

        if (result == "") {
            result = "0";
        }
        return result;
    }
};

int main() {
    Solution sol;
    string result1 = sol.removeKdigits("1432219", 3);
    cout << result1.c_str() << endl;
    string result2 = sol.removeKdigits("100200", 1);
    cout << result2.c_str() << endl;


    return 0;
}