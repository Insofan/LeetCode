// 
// Created by Insomnia on 18-8-15.
//

#include "../../Common/Tree/Travel/TreeNode.h"
#include <iostream>

using namespace std;
struct Solution {
public:
    bool hasSubtree(TreeNode *node, TreeNode *targetNode) {

        bool res = false;
        if (node && targetNode) {
            if (!res) {
                res = hasSubtree(node->left, targetNode);
            }

            if (!res) {
                res = hasSubtree(node->right, targetNode);
            }

            if (node->val == targetNode->val) {
               res = generate(node, targetNode);
            }
        }
        return res;
    }

private:
    bool generate(TreeNode *first, TreeNode *second) {
        if (!first) {
            return false;
        }
        if (!second) {
            return true;
        }
        if (first->val != second->val) {
            return false;
        }

        return generate(first->left, second->left) && generate(first->right, second->right);
    }
};

int main() {
    TreeNode a(8);
    TreeNode b(6);
    TreeNode d(5);
    TreeNode e(7);
    TreeNode f(10);
    TreeNode g(9);
    TreeNode h(11);

    TreeNode a1(6);
    TreeNode a2(6);
    TreeNode a3(6);

    a.left = &b;
    b.left = &d;
    b.right = &e;
    a.right = &f;
    f.left = &g;
    f.right = &h;


    Solution solution;
    cout << boolalpha << solution.hasSubtree(&a, &a) << endl;
    return 0;
}