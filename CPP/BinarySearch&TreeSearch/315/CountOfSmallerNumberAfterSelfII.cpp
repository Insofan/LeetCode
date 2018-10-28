//
// Created by Insomnia on 2018/7/24.
// 在回溯里面 有一种解法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BSTNode {
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x): val(x), count(0), left(NULL), right(NULL){}
};

void BST_insert(BSTNode *node, BSTNode *insertNode, int &countSmall) {
    if (insertNode->val <= node->val) {
        node->count++;
        if (node->left){
            BST_insert(node->left, insertNode, countSmall);
        } else {
            node->left = insertNode;
        }
    } else {
        countSmall += node->count + 1;
        if (node->right) {
            BST_insert(node->right, insertNode, countSmall);
        } else {
            node->right = insertNode;
        }
    }
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        vector<int> res;
        vector<BSTNode *> nodeVec;
        //逆序
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            nodeVec.push_back(new BSTNode(nums[i]));
        }
        //最后一个数的结果肯定是0
        res.push_back(0);

        for (int j = 1; j < nums.size(); j++) {
            int countSmall = 0;
            BST_insert(nodeVec[0], nodeVec[j], countSmall);
            res.push_back(countSmall);
        }
        reverse(res.begin(), res.end());
        return res;
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

    for (int j = 0; j < result.size(); j++) {
      cout << result[j] << " ";
    }
    cout << endl;
    return 0;
}
