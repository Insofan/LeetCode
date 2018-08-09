//
// Created by Insomnia on 2018/8/9.
//
//二叉树直径 , 本质上求深度, 求当前节点两边的最大高度, 和左右深度加起来的最大值
// 光求左右最大深度的和, 考虑条件少

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
    int diameterOfBinaryTree(TreeNode *root) {

        int ld = 0;
        int rd = 0;
        int lp = 0;
        int rp = 0;
        if (!root) {
            return 0;
        }

        if (root->left) {
            ld = maxDepth(root->left);
            lp = diameterOfBinaryTree(root->left);
        }
        if (root->right) {
            rd = maxDepth(root->right);
            rp = diameterOfBinaryTree(root->right);
        }
        return max(max(lp, rp), ld + rd);
    }

private:
    int maxDepth(TreeNode *root) {
        int ld, rd;
        if (root == NULL) {
            return 0;
        } else {
            ld = maxDepth(root->left);
            rd = maxDepth(root->right);
            return 1 + max(ld, rd);
        }
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(4);
    TreeNode d(5);
    TreeNode e(3);

    a.left = &b;
    b.left = &c;
    b.right = &d;
    a.right = &e;
    preorderBinaryTree(0, &a);
    Solution solution;
    cout << solution.diameterOfBinaryTree(&a) << endl;
    return 0;
}
