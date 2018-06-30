//
// Created by Insomnia on 2018/6/30.
//
//https://leetcode.com/problems/jump-game-ii/description/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        //当前可达最大值
        int currentMaxIndex = nums[0];
        //遍历 各个位置过程中， 可达最远位置
        int preMaxMaxIndex = nums[0];
        int jumpMin = 1;

        for (int i = 0; i < nums.size(); ++i) {
            //跳到这里 无法再跳， 说明之前需要跳一步
            if (i > currentMaxIndex) {
                jumpMin++;
                currentMaxIndex = preMaxMaxIndex;
            }

            if (preMaxMaxIndex < nums[i] + i) {
                preMaxMaxIndex = nums[i] + i;
            }
        }
        return jumpMin;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);

    Solution sol;
    cout << sol.jump(nums) << endl;
    return 0;
}