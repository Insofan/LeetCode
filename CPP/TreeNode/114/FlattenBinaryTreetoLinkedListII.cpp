//
// Created by Insomnia on 2018/7/12.
//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preorder(root, last);
    }

private:
    void preorder(TreeNode *node, TreeNode *&last) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            last = node;
            return;
        }

        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *leftLast = NULL;
        TreeNode *rightLast = NULL;

        if (left) {
            preorder(left, leftLast);
            node->left = NULL;
            node->right = left;
            last = leftLast;
        }

        if (right) {
            preorder(right, rightLast);
            if (leftLast) {
                leftLast->right = right;
            }
            last = rightLast;
        }
    }
};

int main() {

    return 0;
}
