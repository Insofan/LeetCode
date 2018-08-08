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

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    }
};
int main () {
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

    return 0;
}