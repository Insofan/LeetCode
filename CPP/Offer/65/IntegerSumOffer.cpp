// 
// @ClassName IntegerSumOffer
// @Description 同leetcode 371
// @Date 18-10-27 下午12:00
// @Created by Insomnia
//

#include <iostream>

using namespace std;

/**
 * bit 运用问题
 */
class Solution {
public:
    int sumOfInteger(int a, int b) {
        return b == 0 ? a : sumOfInteger(a ^ b, (a&b)<<1);
    }
};

int main() {

    Solution solution;
    cout << solution.sumOfInteger(2, 12)<< endl;

    return 0;
}
