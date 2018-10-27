// 
// @ClassName BestTimeToBuyAndSellStockOffer
// @Description 同leetcode 121 Best Time to Buy and Sell Stock
// @Date 18-10-27 上午11:47
// @Created by Insomnia
//

#include <vector>
#include <iostream>
#include <climits>

using  namespace std;

class Solution {
public:
    int maxPro(vector<int> &vec) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < vec.size(); ++i) {
            minPrice = min(minPrice, vec[i]);
            maxPro = max(maxPro, vec[i] - minPrice);
        }
        return maxPro;
    }
};

int main() {
    vector<int> vec{9, 11, 8, 5, 7, 12, 16, 14};
    Solution solution;
    cout << solution.maxPro(vec) << endl;

    return 0;
}

