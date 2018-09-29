//
// Created by Insomnia on 2018/9/29.
// 新写

#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        long long res = 0;
        while (x) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res < INT_MAX && res > INT_MIN) ? res : 0;
    }
};


int main() {

    Solution solution;
    cout << solution.reverse(123) << endl;
    cout << solution.reverse(320) << endl;
    return 0;
}
