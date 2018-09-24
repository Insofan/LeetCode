// 
// Created by Insomnia on 18-9-24.
//

#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    int maxSubSum(vector<int> &vec) {
        vector<int> dp(vec.size());
        int res =INT32_MIN;
        dp[0] = vec[0];
        for (int i = 1; i < vec.size(); ++i) {
           dp[i] = max(vec[i], vec[i] + dp[i - 1]);
           if (dp[i] > res) {
               res = dp[i];
           }
        }
        return res;
    }

};

int main (){

    int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> vector1(&a[0], &a[8]);

    Solution solution;
   cout << solution.maxSubSum(vector1) << endl;

    return 0;
}