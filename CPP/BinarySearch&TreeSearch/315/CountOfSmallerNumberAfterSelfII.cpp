//
// Created by Insomnia on 2018/7/24.
// 在回溯里面 有一种解法

#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};



class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> result;//最终逆序数组
        vector<BSTNode *> nodeVec;

        vector<int> count;

        for (int i = nums.size() - 1; i >= 0; i--) {
            nodeVec.push_back(new BSTNode(nums[i]));
        }

        count.push_back(0);

        for (int j = 0; j < nodeVec.size(); ++j) {
            int countSmall = 0;
            BST_insert(nodeVec[0], nodeVec[j], countSmall);
            count.push_back(countSmall);
        }

        for (int k = nodeVec.size() - 1; k >= 0; k--) {
            delete nodeVec[k];
            result.push_back(count[k]);
        }

        return result;
    }

private:
    void BST_insert(BSTNode *node, BSTNode *insertNode, int &countSmall) {
        if (insertNode->val <= node->val) {
            node->count++;
            if (node->left) {
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
