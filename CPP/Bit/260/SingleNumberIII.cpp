// 
// @ClassName SingleNumberIII
// @Description leetcode 260
// @Date 18-10-21 下午9:38
// @Created by Insomnia
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> vec) {
        vector<int> res(2, 0);
        int xval = 0;

        for (auto val : vec) {
            xval ^= val;
        }

        xval ^= xval & (xval - 1);

        for (int i = 0; i < vec.size(); ++i) {
            if (xval & vec[i]) {
                res[0] ^= vec[i];
            } else {
                res[1] ^= vec[i];
            }

        }

        return res;
    }
};

int main(){
    int a[] = {1,2,1,3,2,5};
    vector<int> vector1(&a[0], &a[6]);

    Solution solution;
    vector<int> res = solution.singleNumber(vector1);
    for (auto val : res) {
        cout << val << " ";
    }
    cout << endl;
    //cout << solution.singleNumber(vector1)[1] << endl;
    return 0;
}