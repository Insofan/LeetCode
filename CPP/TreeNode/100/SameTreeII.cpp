//
// Created by Insomnia on 2018/8/10.
//

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
            return p == q;
        } else {
            return (p->val == q->val ) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
        }

    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(1);

    a.left = &b;
    a.right = &c;

    TreeNode a2(1);
    TreeNode b2(2);
    TreeNode c2(1);
    TreeNode d2(3);

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;

    Solution solution;
    cout << boolalpha << solution.isSameTree(&a, &a2) << endl;

    return 0;
}
