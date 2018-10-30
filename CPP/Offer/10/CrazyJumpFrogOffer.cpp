//
// @ClassName CrazyJumpFrogOffer
// @Description TODO
// @Date 2018/10/30 下午3:45
// @Created by Insomnia
//


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFrog(int number) {
        if (number  < 2) {
            return number;
        }

        vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++) {
            int j = 0;
            while (j < i) {
                dp[i] += dp[j];
                j++;
            }
        }
        return dp[number];
    }
};

int main() {

    cout << "Frog jump 10 ladder:" << endl;
    Solution solution;

    cout << solution.jumpFrog(4) << endl;

    return 0;
}
