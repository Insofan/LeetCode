//
// Created by Insomnia on 2018/6/26.
//

#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    //实际上是维护一个最小堆
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> smallHeap;

        for (int i = 0; i < nums.size(); ++i) {
            //堆中元素小与k 直接进堆
           if (smallHeap.size() < k) {
                smallHeap.push(nums[i]);
           } else if (smallHeap.top() < nums[i]) {
               //如果堆顶 比新元素小， 弹出堆顶， push进入新元素（即替换堆顶）
               smallHeap.pop();
               smallHeap.push(nums[i]);
           }
        }
        return smallHeap.top();
    }
};

int main() {

    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution sol;
    std::cout << sol.findKthLargest(nums, 6) << std::endl;

    return 0;
}