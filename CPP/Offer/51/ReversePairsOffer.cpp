// 
// Created by Insomnia on 18-10-13.
// leetcode 315
// Count of Smaller Numbers After Self

#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

class Solution {
public:
    int reverseParis(vector<int> &nums) {
        vector<pair<int, int>> vec;
        vector<int> count;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
           vec.push_back(make_pair(nums[i], i));
           count.push_back(0);
        }

        mergeSort(vec, count);

        for (int i = 0; i < count.size(); i++) {
            res += count[i];
        }
        return res;
    }

private:
    void mergeSort(vector<pair<int, int>> &vec, vector<int> &count) {
        if (vec.size() < 2) {
            return;
        }
        int mid = vec.size() / 2;
        vector<pair<int, int>> subVec1;
        vector<pair<int, int>> subVec2;

        for (int i = 0; i < mid; i++) {
            subVec1.push_back(vec[i]);
        }
        for (int j = mid; j < vec.size(); j++) {
            subVec2.push_back(vec[j]);
        }

        mergeSort(subVec1, count);
        mergeSort(subVec2, count);
        vec.clear();
        merge(subVec1, subVec2, vec, count);
    }

    void merge(vector<pair<int, int>> &vec1, vector<pair<int, int>> &vec2, vector<pair<int, int>> &vec, vector<int> &count) {
        int i = 0;
        int j = 0;

        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i].first <= vec2[j].first) {
                count[vec1[i].second] += j;
                vec.push_back(vec1[i]);
                i++;
            } else {
                vec.push_back(vec2[j]);
                j++;
            }
        }

        for (;  i< vec1.size() ; i++) {
            count[vec1[i].second] += j;
            vec.push_back(vec1[i]);
        }

        for (; j < vec2.size() ; j++) {
           vec.push_back(vec2[j]);
        }
    }
};

int main() {
    int a[] = {7, 5, 6, 4};
    vector<int> vector1(&a[0], &a[4]);
    Solution solution;
    cout << solution.reverseParis(vector1) << endl;

    return 0;
}