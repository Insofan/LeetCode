//
// Created by Insomnia on 2018/7/9.
//

#include <stdio.h>
#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


using namespace std;
class Solution {
public:
    //用两个栈存储遍历的节点
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> path;
        vector<TreeNode *> nodePPath;
        vector<TreeNode *> nodeQPath;
        int finish = 0;
        preorder(root, p, path, nodePPath, finish);
        path.clear();
        finish = 0;
        preorder(root, q, path, nodeQPath, finish);
        int pathLen = 0;
        if (nodePPath.size() < nodeQPath.size()) {
            pathLen = nodePPath.size();
        } else {
            pathLen = nodeQPath.size();
        }

        TreeNode *result = 0;
        for (int i = 0; i < pathLen; ++i) {
            if (nodePPath[i] == nodeQPath[i]) {
                result = nodePPath[i];
            }
        }
        return result;
    }

    void preorder(TreeNode *node, TreeNode *search, std::vector<TreeNode *> &path, std::vector<TreeNode *> &result, int &finish) {
        if (!node || finish == 1) {
            return;
        }

        path.push_back(node);

        if (node == search) {
            finish = 1;
            result = path;
        }

        preorder(node->left, search, path, result, finish);
        preorder(node->right, search, path, result, finish);
        path.pop_back();
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;

    Solution sol;
    TreeNode *result = sol.lowestCommonAncestor(&a, &b, &f);
    cout << result->val << endl;
    result = sol.lowestCommonAncestor(&a, &d, &z);
    cout << result->val << endl;
    result = sol.lowestCommonAncestor(&a, &b, &y);
    cout << result->val << endl;

    return 0;
}
