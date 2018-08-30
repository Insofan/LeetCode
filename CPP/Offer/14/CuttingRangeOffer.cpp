// 
// Created by Insomnia on 18-8-30.
//

#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    int cuttingRange(int length) {

        /*
        if (length == 0) {
            return  0;
        }
         */
        if (length <= 1) {
            return 0;
        }

        if (length == 2) {
            return  1;
        }
        if (length == 3) {
            return  2;
        }
        int res = 0;
        vector<int> dp(length + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        int temp;
        int max;
        for (int i = 4; i <= length ; i++) {
            max = 0;

            for (int j = 1; j <= i / 2 ; j++) {
                temp = dp[j] * dp[i - j];
                if (temp > max) {
                    max = temp;
                }
            }
            dp[i] = max;
        }

        return dp[length];
    }
};

int main() {

    Solution solution;

    cout << "8 : " << solution.cuttingRange(8) << endl;
    cout << "6 : " << solution.cuttingRange(6) << endl;
    cout << "7 : " << solution.cuttingRange(7) << endl;



    return  0;
}