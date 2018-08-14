//
// Created by Insomnia on 2018/8/14.
//

#include "TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

void preOrderTraverse(TreeNode *root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void preOrderStackTraverse(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != NULL) {
        while (p) {
            s.push(p);
            cout << p->val << " ";
            p = p->left;
        }

        p = s.top();
        s.pop();
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

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    preOrderTraverse(&a);
    cout << endl;

    preOrderStackTraverse(&a);

    return 0;
}
