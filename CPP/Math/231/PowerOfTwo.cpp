// 
// Created by Insomnia on 18-8-12.
//

//判断一个数是否为2的次方
#include <iostream>

using namespace std;

class Solution {
public:
    bool  isPowerOfTwoGood(int n) {
        
//        return n > 0 && ((n & (n - 1)) == 0);
        return n > 0 && !(n & (n - 1));
    }
    bool isPowerOfTwoBad(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        if (n % 2 == 1) {
            return false;
        }

        return isPowerOfTwoBad(n / 2);
    }
};
int main() {
    Solution solution;

    cout << boolalpha << solution.isPowerOfTwoBad(10) << endl;
    cout << boolalpha << solution.isPowerOfTwoGood(16) << endl;
    cout << boolalpha << solution.isPowerOfTwoGood(24) << endl;
    cout << boolalpha << solution.isPowerOfTwoGood(1024) << endl;

}