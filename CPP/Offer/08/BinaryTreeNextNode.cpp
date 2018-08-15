// 
// Created by Insomnia on 18-8-15.
//

#include <stack>
#include <iostream>

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(char x):val(x), left(NULL), right(NULL), next(NULL){}
};

using namespace std;

class Solution {
public:
    char nextNode(TreeNode *root, char target) {

        TreeNode *p = root;
        stack<TreeNode *> s;

    }
};


void preOrderTraverse(TreeNode *root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

int main() {

        TreeNode a('a');
        TreeNode b('b');
        TreeNode c('c');
        TreeNode d('d');
        TreeNode e('e');
        TreeNode f('f');
        TreeNode g('g');
        TreeNode h('h');
        TreeNode i('i');

        a.left = &b;
        a.right = &c;
        b.left = &d;
        b.right = &e;
        e.left = &h;
        e.right = &i;
        c.left = &f;
        c.right = &g;

    preOrderTraverse(&a);
    cout << endl;
    /*
        Solution solution;
        char res = solution.nextNode(&a, 'd');
    cout << res << endl;
     */
    return 0;
}