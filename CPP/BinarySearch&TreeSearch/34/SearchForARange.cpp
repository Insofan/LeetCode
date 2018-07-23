//
// Created by Insomnia on 2018/7/23.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result;
        result.push_back(leftBound(nums, target));
        result.push_back(rightBound(nums, target));
        return result;
    }

private:
    int leftBound(vector<int> &nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;

    while (begin <= end) {
       int mid = (begin + end) / 2;
       if (target == nums[mid]) {
          if (mid == 0 || nums[mid - 1] < target) {
              return mid;
          }
          begin = mid - 1;
       }else if (target < nums[mid]) {
           end = mid - 1;

       } else if (target > nums[mid])  {
           begin = mid + 1;
       }
    }
    return -1;
}

int rightBound(vector<int> &nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;

    while (begin <= end) {
       int mid = (begin + end) / 2;
       if (target == nums[mid]) {
          if (mid == nums.size() - 1 || nums[mid + 1] > target) {
              return mid;
          }
          begin = mid + 1;
       }else if (target < nums[mid]) {
           end = mid - 1;
       } else if (target > nums[mid])  {
           begin = mid + 1;
       }
    }
    return -1;
}

};




int main() {
    int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
    vector<int> nums;
    for (int i = 0; i < 8; ++i) {
        nums.push_back(test[i]);
    }
    
    Solution sol;

    for (int j = 0; j < 12; ++j) {
        vector<int> res = sol.searchRange(nums, j);
        cout << j << " "<< res[0] << " " << res[1] << endl;
    }

    return 0;
}
