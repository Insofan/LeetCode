// 
// Created by Insomnia on 18-8-15.
//

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


using namespace std;

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *node) {
        if (!node) {
            return NULL;
        }
        TreeNode *tempNode = node->left;
        node->left = mirrorTree(node->right);
        node->right = mirrorTree(tempNode);
        return node;
    }

};


void postorder(TreeNode *node) {
    TreeNode *p = node;
    TreeNode *last = NULL;
    stack<TreeNode *> s;

    while (!s.empty() || p != NULL) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            TreeNode *top = s.top();
            if (top->right && (top->right != last)) {
                p = top->right;
            } else {
                cout << top->val << " ";
                last = top;
                s.pop();
            }
        }

    }
    cout << endl;
}

int main() {
    TreeNode a(8);
    TreeNode b(6);
    TreeNode d(5);
    TreeNode e(7);
    TreeNode f(10);
    TreeNode g(9);
    TreeNode h(11);

    a.left = &b;
    b.left = &d;
    b.right = &e;
    a.right = &f;
    f.left = &g;
    f.right = &h;

    postorder(&a);

    Solution solution;
    solution.mirrorTree(&a);
    postorder(&a);

    return 0;
}