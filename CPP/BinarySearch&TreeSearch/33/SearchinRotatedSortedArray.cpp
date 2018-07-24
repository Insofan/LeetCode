//
// Created by Insomnia on 2018/7/24.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {

        int begin = 0;
        int end = nums.size() - 1;

        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                if (nums[begin] < nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else if (nums[begin] > nums[mid]) {
                    end = mid - 1;
                    //begin mid 重合, 两个元素时
                } else if (nums[begin] == nums[mid]) {
                    begin = mid + 1;
                }
            } else if (target > nums[mid]) {
                if (nums[begin] < nums[mid]) {
                   begin = mid + 1;
                } else if (nums[begin] > nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else if (nums[begin] == nums[mid]) {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {

    int test[] = {9, 12, 15, 20, 1, 3, 6, 7};

    vector<int> nums;
    for (int i = 0; i < 8; ++i) {
        nums.push_back(test[i]);
    }

    Solution sol;
    for (int j = 0; j < 22; ++j) {
       cout << j << " " << sol.search(nums, j) << endl;
    }

    return 0;
}
