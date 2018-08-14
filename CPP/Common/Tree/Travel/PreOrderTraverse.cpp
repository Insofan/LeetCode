//
// Created by Insomnia on 2018/8/14.
//

#include "TreeNode.h"
#include <iostream>

//struct TreeNode {
//    int x;
//    TreeNode *left;
//    TreeNode *right;
//};

using namespace std;

void preOrderTraverse(TreeNode *root) {
    if (!root) {
        return;
    }
    
    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

int main() {
    TreeNode a('A');
    TreeNode b('B');
    TreeNode c('C');
    TreeNode d('D');
    TreeNode e('E');
    TreeNode f('F');
    TreeNode g('G');

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    
    preOrderTraverse(&a);

    return 0;
}
