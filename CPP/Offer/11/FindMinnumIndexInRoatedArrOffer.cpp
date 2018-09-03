//
// Created by Insomnia on 2018/9/3.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinnumIndex(vector<int> &vec, int target) {
        int res = -1;

        int begin = 0;
        int end   = vec.size() - 1;

        while (begin < end) {
            int mid = (begin + end) / 2;
            if (target == vec[mid]) {
                return mid;
            }
            if (vec[begin] <= vec[mid]) {
                if (target >= vec[begin] && target < vec[mid]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else {

                if (target > vec[mid] && target <= vec[end]) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }

            }
        }


        return vec[begin] == target ? begin : -1;
    }
};


int main() {

    int arr[7] = {4, 5, 6, 7, 0, 1, 2};

    vector<int> vec(&arr[0], &arr[7]);
    Solution solution;
    cout << solution.findMinnumIndex(vec, 5) <<endl ;
    return 0;
}
