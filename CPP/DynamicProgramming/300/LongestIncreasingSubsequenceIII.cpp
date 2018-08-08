//
// Created by Insomnia on 2018/8/7.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> nums, int target) {
    int index = -1;
    int begin = 0;
    int end = nums.size() - 1;

    while (index == -1) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            index = mid;
        } else if (target < nums[mid]) {
            if (mid == 0 || target > nums[mid - 1]) {
                index = mid;
            }
            end = mid - 1;
        } else {
            if (mid == nums.size() - 1 || target < nums[mid + 1]) {
                index = mid + 1;
            }
            begin = mid + 1;
        }
    }

    return index;
}


class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> stack;

        stack.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                int pos = binarySearch(stack, nums[i]);
                stack[pos] = nums[i];
            }

        }
        return stack.size();
    }
};


int main() {
    int test[] = {1, 2, 3, 2, 10, 4};
    vector<int> nums;

    for (int i = 0; i < 6; ++i) {
       nums.push_back(test[i]);
    }

    Solution solution;

    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}
