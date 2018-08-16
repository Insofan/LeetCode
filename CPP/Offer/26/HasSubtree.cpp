// 
// Created by Insomnia on 18-8-15.
//

#include "../../Common/Tree/Travel/TreeNode.h"
#include <iostream>

using namespace std;
struct Solution {
public:
    bool hasSubtree(TreeNode *s, TreeNode *t) {
        if (!s) {
            return false;
        }

        if (isSame(s, t)) {
            return true;
        }

        return hasSubtree(s->left, t) || hasSubtree(s->right, t);
    }

private:
    bool isSame(TreeNode *first, TreeNode *second) {
        if (!first || !second) {
            return first == second;
        } else {
            return (first->val == second->val) && isSame(first->left, second->left) && isSame(first->right, second->right);
        }
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(4);
    TreeNode d(1);
    TreeNode e(2);
    TreeNode f(5);

    TreeNode a1(4);
    TreeNode a2(1);
    TreeNode a3(2);

    a.left = &b;
    b.left = &d;
    b.right = &e;
    a.right = &f;


    a1.left = &a2;
    a1.right = &a3;

    Solution solution;
    cout << boolalpha << solution.hasSubtree(&a, &a1) << endl;
    return 0;
}