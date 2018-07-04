//
// Created by Insomnia on 2018/7/4.
//
//88 将两个已经排序的链表, 按递增顺序合并到第一个链表上,  结果是
//ut:
//[1,2,3,0,0,0]
//3
//[2,5,6]
//3
//[1,3,3,5,0,6]
//excpeted: [1,2,2,3,5,6]
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (nums2.size() == 0) {
            return;
        }
        int j = m - 1;
        int k = n - 1;
        int len = m + n;
        for (int i = len - 1; i >= 0; i--) {
            if (nums1[j] >= nums2[k]) {
                nums1[i] = nums1[j--];
            } else {
                nums1[i] = nums2[k--];
            }
            i--;
        }
    }
};

int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);

    Solution sol;
    sol.merge(nums1, )


    return 0;
}
