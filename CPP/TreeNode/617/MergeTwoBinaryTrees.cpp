// 
// Created by Insomnia on 18-8-8.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void preorderBinaryTree(int layer, TreeNode *node) {
    if (!node) {
        return;
    }

    for (int i = 0; i < layer; ++i) {
        cout << "--";
    }
    cout << node->val << endl;
    preorderBinaryTree(layer + 1, node->left);
    preorderBinaryTree(layer + 1, node->right);
}

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1) {
            return t2;
        } else if (!t2) {
            return t1;
        }

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};


int main() {
    TreeNode a1(1);
    TreeNode b1(3);
    TreeNode c1(2);
    TreeNode d1(5);

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;

    TreeNode a2(2);
    TreeNode b2(1);
    TreeNode c2(4);
    TreeNode d2(3);
    TreeNode e2(7);

    a2.left = &b2;
    b2.right = &c2;
    a2.right = &d2;
    d2.right = &e2;

    Solution solution;
    TreeNode *resNode = solution.mergeTrees(&a1, &a2);
    preorderBinaryTree(0, resNode);

    return 0;
}