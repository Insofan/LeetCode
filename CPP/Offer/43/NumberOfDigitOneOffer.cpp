// 
// Created by Insomnia on 18-9-28.
//

//leetcode 233 https://leetcode.com/problems/number-of-digit-one/description/

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfDigitOne(int n) {
        int res = 0;
        for (long long m = 1;  m <= n; m *= 10) {
            //n / m + 8 算是否大于1,
            res += (n / m  + 8) /10 * m  + (n/m %10 == 1) * (n %m +1);
        }
        return res;
    }

};

int main() {
    Solution solution;
    //20
    cout << solution.numberOfDigitOne(99) << endl;
    //20 + 120
    cout << solution.numberOfDigitOne(199) << endl;
    //9 * 20 + 120
    cout << solution.numberOfDigitOne(999) << endl;
    return 0;
}