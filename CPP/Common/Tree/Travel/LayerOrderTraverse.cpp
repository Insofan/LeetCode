//
// Created by Insomnia on 2018/8/21.
//

#include <stdio.h>
#include "TreeNode.h"
#include <queue>

using namespace std;
void layerOrderTraverse(TreeNode *node) {
    //错误

    queue<TreeNode *> s;
    s.push(node);
    while (!s.empty()) {
        TreeNode *front = s.front();
        cout << node->val << " ";
        s.pop();
        if (front->left) {
            s.push(front->left);
        }
        if (front->right) {
            s.push(front->right);
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

    layerOrderTraverse(&a);

    return 0;
}
