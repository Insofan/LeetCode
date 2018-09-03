//
// Created by Insomnia on 2018/9/3.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using  namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main() {
    int arr[] = {3,4,5,1,2};
    vector<int> vector1(&arr[0], &arr[5]);

    Solution solution;
    cout <<  solution.findMin(vector1) << endl;
    return 0;
}
