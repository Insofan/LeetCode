//
// Created by Insomnia on 2018/8/14.
//

#include <stdio.h>
#include "TreeNode.h"
#include <iostream>

using namespace std;

void postOrderTraverse(TreeNode *root) {
    if (root) {
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        cout << root->val << " ";
    }
    
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

    postOrderTraverse(&a);
    return 0;
}
