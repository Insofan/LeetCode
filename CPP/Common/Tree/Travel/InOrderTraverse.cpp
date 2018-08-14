//
// Created by Insomnia on 2018/8/14.
//

#include <stdio.h>
#include "TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

void inOrderTraverse(TreeNode *root) {
    if (root) {
        inOrderTraverse(root->left);
        cout << root->val << " ";
        inOrderTraverse(root->right);
    }
}

void inOrderStackTraverse(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;

    while (!s.empty() || p != NULL) {
        while (p) {
            s.push(p);
            p = p->left;
        }

        p = s.top();
        s.pop();
        cout << p->val << " ";
        p = p->right;
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
    TreeNode d1('1');

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    d.left = &d1;

    inOrderTraverse(&a);
    cout << endl;
    inOrderStackTraverse(&a);

    return 0;
}
