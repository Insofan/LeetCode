//
// Created by Insomnia on 2018/7/9.
//

#include <stdio.h>
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        //路径栈
        vector<int> path;
        //路径值
        int pathValue = 0;
        preorder(root, pathValue, sum, path, result);

        return result;
    }

private:
    void preorder(TreeNode *node, int &pathValue, int sum, vector<int> &path, vector<vector<int>> &result) {
        if (!node) {
            return;
        }

        pathValue += node->val;
        path.push_back(node->val);

        if (pathValue == sum && !node->left && !node->right) {
            result.push_back(path);
        }

        preorder(node->left, pathValue, sum, path, result);
        preorder(node->right, pathValue, sum, path, result);

        pathValue -= node->val;
        path.pop_back();

    }
};


int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(&a, 22);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
