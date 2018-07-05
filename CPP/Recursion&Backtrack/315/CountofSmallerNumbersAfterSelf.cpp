//
// Created by Insomnia on 2018/7/5.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<pair<int, int>> vec;
        vector<int> count;

        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0);
        }

        mergeSort(vec, count);
        return count;

    }

private:
    void mergeSort(vector<pair<int, int>> &vec, vector<int> &count) {
        if (vec.size() < 2) {
            return;
        }

        int mid = vec.size() / 2;

        vector<pair<int, int>> subVec1;
        vector<pair<int, int>> subVec2;

        for (int i = 0; i < mid; ++i) {
            subVec1.push_back(vec[i]);
        }

        for (int j = mid; j < vec.size(); ++j) {
            subVec2.push_back(vec[j]);
        }
        mergeSort(subVec1, count);
        mergeSort(subVec2, count);
        vec.clear();

        mergeTwoVec(subVec1, subVec2, vec, count);
    }

    void mergeTwoVec(vector<pair<int, int>> &subVec1, vector<pair<int, int>> &subVec2, vector<pair<int, int>> &vec,
                     vector<int> &count) {
        int i = 0;
        int j = 0;
        while (i < subVec1.size() && j < subVec2.size()) {
            if (subVec1[i].first <= subVec2[j].first) {
                count[subVec1[i].second] += j;
                vec.push_back(subVec1[i]);
                i++;
            } else {
                vec.push_back(subVec2[j]);
                j++;
            }
        }

        for (; i < subVec1.size(); i++) {
            count[subVec1[i].second] += j;
            vec.push_back(subVec1[i]);
        }

        for (; j < subVec2.size(); j++) {
            vec.push_back(subVec2[j]);
        }
    }
};

int main() {
    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
    vector<int> nums;
    for (int i = 0; i < 8; ++i) {
        nums.push_back(test[i]);
    }
    Solution sol;
    vector<int> result = sol.countSmaller(nums);
    for (int j = 0; j < result.size(); ++j) {
       cout << result[j] << ' ';
    }


    cout << endl;
    return 0;
}