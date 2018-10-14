// 
// Created by Insomnia on 18-10-14.
// leetcode 34
// Find First and Last Position of Element in Sorted Array

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findNumCountInArr(vector<int> &vec, int tar) {
        int tarLow = binarySearch(vec, tar);
        int tarNextLow = binarySearch(vec, tar + 1);
        //因为目标下一个数的index 是tarNextLow, 所有tar的index是 tarLow 到 tarNextLow - 1
        if (tarLow <= vec.size() && vec[tarLow] == tar && tarNextLow - 1 <= vec.size() && vec[tarNextLow - 1] == tar) {
            return tarNextLow - tarLow;
        } else {
            return -1;
        }
    }

    int binarySearch(vector<int> &vec, int tar) {
        int l = 0;
        int r = vec.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid] < tar) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    int a1[] = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> vec(&a1[0], &a1[8]);
    Solution solution;

    cout << "3: " << solution.findNumCountInArr(vec, 3) << endl;
    cout << "2: " << solution.findNumCountInArr(vec, 2) << endl;
    cout << "4: " << solution.findNumCountInArr(vec, 4) << endl;
    return 0;
}
