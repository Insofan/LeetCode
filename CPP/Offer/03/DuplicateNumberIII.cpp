// 
// Created by Insomnia on 18-8-12.
//

//这种做法还跑不通
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateNumber(vector<int> & vec) {
        if (vec.size() == 0) {
            return  0;
        }

        int start = 1;
        int end = vec.size() - 1;

        while (end >= start) {
            int mid = start + ((end - start) >> 1);

            int count = countRange(vec, start, end);

            if (end == start) {
                if (count > 1) {
                    return start;
                } else {
                    break;
                }
            }

            if (count > (mid - start + 1)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return  -1;
    }

private:
    int countRange(vector<int> &vec, int start, int end) {
        if (vec.size() == 0) {
            return  0;
        }

        int count = 0;

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] >= start && vec[i] <= end) {
                ++count;
            }
        }

        return count;
    }
};
int main () {
    int nums[7] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> vec;
    for (int i = 0; i < 7; ++i) {
        vec.push_back(nums[i]);
    }

    Solution solution;

    cout << solution.duplicateNumber(vec) << endl;

    return  0;
}