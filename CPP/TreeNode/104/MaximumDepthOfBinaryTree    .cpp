//
// Created by Insomnia on 2018/8/9.
//
//没一个left或者right + 1 求最大的
#include <stdio.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        int ld, rd;
        if (root == NULL) {
            return 0;
        }
        ld = 1 + maxDepth(root->left);
        rd = 1 + maxDepth(root->right);
        if (ld > rd) {
            return ld;
        } else {
            return rd;
        }
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(7);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    Solution solution;
    cout << solution.maxDepth(&a) << endl;

    return 0;
}
