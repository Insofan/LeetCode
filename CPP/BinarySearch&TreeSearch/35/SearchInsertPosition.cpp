//
// Created by Insomnia on 2018/7/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int> &num, int target) {
    int index = -1;
    int begin = 0;
    int end = num.size() - 1;

    while (index == -1) {
        int mid = (begin + end) / 2;
        if (target == num[mid]) {
            index = mid;
        } else if (target < num[mid]) {
            if (target > num[mid - 1]  || mid == 0) {
                index = mid;
            }
            end = mid - 1;
        } else if (target > num[mid]) {
            if (mid == num.size() - 1 || target < num[mid + 1]  ) {
                index = mid + 1;
            }
            begin = mid + 1;
        }
    }

    return index;
}

int main() {
     int  test[] = {1, 3, 5, 6};
     vector<int> nums;
    for (int i = 0; i < 4; ++i) {
       nums.push_back(test[i]) ;
    }

    for (int j = 0; j < 8; ++j) {
       cout << searchInsert(nums, j) << endl;
    }

    return 0;
}
