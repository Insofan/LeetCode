//
// Created by Insomnia on 2018/8/30.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            return 1 / x * myPow(1 / x, -(n + 1));
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};

int main() {

    Solution solution;

    cout << "2.10 ^ 5: " << solution.myPow(2.10, 5)<< endl;
    cout << "2.0 ^ 3: " << solution.myPow(2.0, 3)<< endl;
    cout << "10.10 ^ 5: " << solution.myPow(10.10, 5)<< endl;
    cout << "10.0 ^ 5: " << solution.myPow(10.0, 5)<< endl;

    return 0;
}
