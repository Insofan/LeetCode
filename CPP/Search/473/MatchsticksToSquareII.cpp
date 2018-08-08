
//
// Created by Insomnia on 2018/8/1.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int> &nums) {

        if (nums.size() < 4) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 4 != 0) {
            return false;
        }


        int target = sum / 4;

        vector<int> okSubset;
        vector<int> okHalf;

        int all = 1 << nums.size();

        for (int i = 0; i < all; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) {
                    sum += nums[j];
                }
            }

            if (sum == target) {
                okSubset.push_back(i);
            }
        }

        for (int i = 0; i < okSubset.size(); ++i) {
            for (int j = i + 1; j < okSubset.size(); ++j) {
                if ((okSubset[i] & okSubset[j]) == 0) {
                    okHalf.push_back(okSubset[i] | okSubset[j]);
                }
            }
        }

        for (int i = 0; i < okHalf.size(); ++i) {
            for (int j = i + 1; j < okHalf.size(); ++j) {
                if ((okHalf[i] & okHalf[j]) == 0) {
                    return true;
                }
            }
        }
        return false;
    }

};


int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);

    Solution solution;
    cout << solution.makesquare(nums) << endl;

    return 0;
}
