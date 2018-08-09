//
// Created by Insomnia on 2018/8/9.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode *tempNode = root->left;
        root->left = invertTree(root->right);
        root->right= invertTree(tempNode);

        return root;
    }
};
int main() {
    TreeNode a(4);
    TreeNode b(2);
    TreeNode c(1);
    TreeNode d(3);
    TreeNode e(7);
    TreeNode f(6);
    TreeNode g(9);

    a.left = &b;
    b.left = &c;
    b.right = &d;

    a.right = &e;
    e.left = &f;
    e.right = &g;

    preorderBinaryTree(0, &a);


    Solution solution;
    TreeNode *res = solution.invertTree(&a);

    cout << "--------------------------------------" << endl;
    preorderBinaryTree(0, res);

    return 0;
}
