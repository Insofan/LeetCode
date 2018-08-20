//
// Created by Insomnia on 2018/8/20.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode *lowestAncter(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *res;
        vector<TreeNode *> pPath;
        vector<TreeNode *> qPath;
        vector<TreeNode *> path;
        int finish = 0;
        generate(root, p, path, pPath, finish);
        path.clear();
        finish = 0;
        generate(root, q, path, qPath, finish);
        int len = min(qPath.size(), pPath.size());

        for (int i = 0; i < len; ++i) {
            if (qPath[i] == pPath[i]){
                res = qPath[i];
            }
        }

        return res;
    }
private:
    void generate(TreeNode *node, TreeNode *search, vector<TreeNode *> &path, vector<TreeNode *> &resPath, int &finish) {
        if (!node || finish == 1) {
            return;
        }

        path.push_back(node);

        if (node == search) {
            finish = 1;
            resPath = path;
        }

        generate(node->left, search, path, resPath, finish);
        generate(node->right, search, path, resPath, finish);
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

    Solution solution;
    cout  << solution.lowestAncter(&a, &b, &c)->val << endl;
    cout  << solution.lowestAncter(&a, &b, &e)->val << endl;
    return 0;
}
