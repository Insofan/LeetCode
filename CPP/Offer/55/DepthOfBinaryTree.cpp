// 
// Created by Insomnia on 18-8-14.
//

//例题2：判断一个树是否为平衡二叉树， 还没做

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


class Solution {
public:
    int depthOfBinaryTree(TreeNode *node) {
        if (!node) {
            return 0;
        } else {
            int ld = depthOfBinaryTree(node->left);
            int rd = depthOfBinaryTree(node->right);
            return  1 + max(ld, rd);
        }
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    g.left = &h;

    Solution solution;

    cout << solution.depthOfBinaryTree(&a) << endl;

    return 0;
}