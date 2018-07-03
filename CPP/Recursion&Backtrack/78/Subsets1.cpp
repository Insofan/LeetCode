//
// Created by Insomnia on 2018/7/3.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

};


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>>res;
    Solution sol;
    res =  sol.subsets(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
