//
// @ClassName AtoI
// @Description TODO
// @Date 2019/1/24 1:26 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int base = 0;

        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '+') {
            sign = 1;
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {

            if ((base  > INT32_MAX / 10) || ((base == INT32_MAX  / 10 ) && str[i] > '7')) {
               if (sign == 1) {
                    return INT32_MAX;
               }
                return INT32_MIN;
            }

            base = 10 * base + str[i++] - '0';
        }


        return sign * base;
    }
};

int main() {
    vector<string> vec = {
            "42",
            "   -42",
            "4193 with words",
            "words and 987",
            "-91283472332"
    };

    vector<int> want = {
           42,
           -42,
           4193,
           0,
           -2147483648
    };


    Solution    sol;
    vector<int> res;

    for (int i = 0; i < vec.size(); i++) {
        int tmp = sol.myAtoi(vec[i]);
        res.push_back(tmp);
    }

    for (int i = 0; i < res.size(); ++i) {
       if (res[i] != want[i]) {
           cout << "want: " << want[i] << " res: " << res[i] << endl;
           return -1;
       }
    }
    cout << "A to i bingo" << endl;
    return 0;
}
