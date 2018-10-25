//
// @ClassName NumberOf1Bits
// @Description 191 Number of 1 Bits
// @Date 2018/10/25 上午9:18
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;
class Solution {
public:
    int numOfBits(int n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res++;
        }
        return res;
    }
};


int main() {
    Solution solution;
    
    cout << solution.numOfBits(2) << endl;
    cout << solution.numOfBits(8) << endl;
    cout << solution.numOfBits(9) << endl;

    return 0;
}
