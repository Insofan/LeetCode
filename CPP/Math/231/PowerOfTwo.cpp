// 
// Created by Insomnia on 18-8-12.
//

//判断一个数是否为2的次方
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        if (n % 2 == 1) {
            return false;
        }

        return isPowerOfTwo(n / 2);
    }
};
int main() {
    Solution solution;

    cout << boolalpha << solution.isPowerOfTwo(10) << endl;
    cout << boolalpha << solution.isPowerOfTwo(16) << endl;
    cout << boolalpha << solution.isPowerOfTwo(24) << endl;
    cout << boolalpha << solution.isPowerOfTwo(1024) << endl;

}