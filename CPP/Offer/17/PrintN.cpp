//
// @ClassName PrintN
// @Description TODO
// @Date 2018/11/29 4:10 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:

    void  helper2(string &str) {

        int len = str.length();
        bool isOver = false;
        for (int i = 0; i < len; i++) {
            if (isOver && str[i] != '0') {
                isOver = false;
            }

            if (!isOver) {
                cout << str[i];
            }
        }

        cout << endl;
    }

    void helper1(string &str, int len, int index) {
        if (index == len - 1) {
            helper2(str);
            return;
        }

        for (int i = 0; i < 10; i++) {
            str[index + 1] = i + '0';
            helper1(str, len, index + 1);
        }
    }

    string printN(int n) {
        if (n <= 0){
            return "";
        }

        string res = "";
        res.append(n, '0');

        for (int i = 0; i < 10; i++) {
            res[0] = i + '0';
            helper1(res, n, 0);
        }

        return res;
    }

private:

};

int main() {

    Solution sol = Solution();
    sol.printN(3);
    return 0;
}
