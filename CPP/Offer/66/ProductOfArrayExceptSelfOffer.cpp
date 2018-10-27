// 
// @ClassName ProductOfArrayExceptSelfOffer
// @Description 238 leetcode Product of Array Except Self
// @Date 18-10-27 下午8:48
// @Created by Insomnia
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> exceptSelf(vector<int> &vec) {
        int len = vec.size();
        vector<int> res(len, 1);
        int fromBegin = 1;
        int fromEnd = 1;

        //乘了所有该数字之前的
        for (int i = 0; i < len; i++) {
            res[i] *= fromBegin;
            fromBegin *= vec[i];
        }


        //乘了所有该数字之后的
        for (int j = len - 1; j >= 0; j--) {
            res[j] *= fromEnd;
            fromEnd *= vec[j];
        }
        return res;
    }
};

/**
 * 构建一个数组, 数组每一位是除自己以外其他数字的乘积
 * @return
 */
int main() {
    vector<int> vec{1, 2, 3, 4};
    Solution solution;
    vector<int> res =  solution.exceptSelf(vec);
    for (auto val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
