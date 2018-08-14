//
// Created by Insomnia on 2018/8/14.
//

#include <stdio.h>
#include "TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

void postOrderTraverse(TreeNode *root) {
    if (root) {
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        cout << root->val << " ";
    }
}

void postOrderStackTraverse(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    TreeNode *last = NULL;

    while (!s.empty() || p != NULL) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            TreeNode *top = s.top();
            //是否第一次出现在栈顶
            if (top->right && (last != top->right)) {
               p = top->right;
            } else {
                cout << top->val << " ";
                last = top;
                s.pop();
            }
        }
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
    cout << endl;
    postOrderStackTraverse(&a);
    return 0;
}
