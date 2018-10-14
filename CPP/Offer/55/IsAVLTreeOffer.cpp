// 
// Created by Insomnia on 18-10-14.
// 同 leetcode 110
// Balanced Binary Tree

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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int ld = depthOfTree(root->left);
        int rd = depthOfTree(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && abs(ld - rd) <= 1;
    }

private:

    int depthOfTree(TreeNode *node) {
        if (!node) {
            return 0;
        }

        int ld = depthOfTree(node->left);
        int rd = depthOfTree(node->right);
        return max(ld, rd) + 1;
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
    cout << boolalpha << solution.isBalanced(&a) << endl;
    return 0;
}