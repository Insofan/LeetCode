//
// Created by Insomnia on 2018/8/17.
//

//同leetcode 101
#include "../TreeNode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            true;
        }

        TreeNode *tempNode = mirror(root->left);

        if (isSame(tempNode, root->right)) {
            return true;
        }

        return false;
    }

private:
    TreeNode *mirror(TreeNode *node) {
        if (!node) {
            return NULL;
        }

        TreeNode *tempNode = node->left;
        node->left = mirror(node->right);
        node->right = mirror(tempNode);

        return node;
    }

    bool isSame(TreeNode *one, TreeNode *two) {
        if (!one || !two) {
            return one == two;
        } else {
            return one->val == two->val && isSame(one->left, two->left) && isSame(one->right, two->right);
        }
    }
};

int main() {
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(2);
    TreeNode a4(3);
    TreeNode a5(4);
    TreeNode a6(3);
    TreeNode a7(4);

    TreeNode b1(1);
    TreeNode b2(2);
    TreeNode b3(2);
    TreeNode b4(3);
    TreeNode b5(4);
    TreeNode b6(3);
    TreeNode b7(4);

    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a7;
    a3.right = &a6;

    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b7;
    b3.right = &b6;

    Solution solution;
    cout << boolalpha  << solution.isSymmetric(&a1)<< endl;

    return 0;
}
