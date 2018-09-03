//
// Created by Insomnia on 2018/9/3.
//

#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findMinNum(vector<int> &vec) {
        int left = 0;
        int right = vec.size()  - 1;
        while (left < right) {
            int mid = (left + right)  / 2;

            if (vec[mid] > vec[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vec[left];

    }
    int findMinNumTrick(vector<int> &vec) {
        return *min_element(vec.begin(), vec.end());
    }
};

int main() {
    int a[] = {4, 5, 6, 7, 10, 1, 2};
    vector<int> vec(&a[0], &a[7]);

    Solution solution;

//    cout <<  solution.findMinNumTrick(vec)<<  endl;
    cout <<  solution.findMinNum(vec)<<  endl;

    return 0;
}
