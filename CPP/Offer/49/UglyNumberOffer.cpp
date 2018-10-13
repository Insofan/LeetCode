// 
// Created by Insomnia on 18-10-13.
//

#include <vector>
#include <climits>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isUglyNum(int target) {
        bool res = false;
        if (target > INT_MAX || target < INT_MIN || target == 0) {
            res = false;
        }

        //注意丑数 只能是 positive的 所有需要校验target
        for (int i = 2; i < 6 && target; i++) {
            while (target % i == 0) {
                target /= i;
            }
        }
        return target == 1;
    }
};


int main() {
    int a = 6;
    int b = 8;
    int c = 14;

    Solution solution;
    cout <<  a << " " << boolalpha << solution.isUglyNum(a) << endl;
    cout <<  b << " " << boolalpha << solution.isUglyNum(b) << endl;
    cout <<  c << " " << boolalpha << solution.isUglyNum(c) << endl;
    return 0;
}