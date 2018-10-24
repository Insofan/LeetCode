// 
// @ClassName DiceSumOffer
// @Description N个骰子, 点数为s的
// @Date 18-10-24 下午10:33
// @Created by Insomnia
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, double>> printProbability(int n) {
        vector<pair<int, double>> res;
        vector<vector<double>> f(n + 1, vector<double>( 6 * n + 1));

        //为一个骰子时赋值
        for (int i = 1; i <= 6 ; i++) {
           f[1][i] = 1.0 / 6;
        }

        //第二个骰子开始
        for (int i = 2; i <= n ; i++) {
            //和从i开始
            for (int j = i; j <= 6 * n; j++) {
                //六种可能性
                for (int k = 0; k <= 6; k++) {
                    if (j > k) {
                        f[i][j] += f[i - 1][j - k];
                    }
                }
                f[i][j] /= 6.0;
            }
        }

        for (int i = n; i <= 6 * n; i++) {
           res.push_back(make_pair(i, f[n][i]));
        }

        return res;
    }
};

int main() {

    Solution solution;
    vector<pair<int, double>> res =  solution.printProbability(2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " : " << res[i].second << endl;
    }

    return 0;
}