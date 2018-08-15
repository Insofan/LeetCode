//
// Created by Insomnia on 2018/8/15.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrderWithStack(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    while(!s.empty() || p !=NULL) {
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

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int >path;
        int pathSum = 0;

        generate(root, sum, pathSum, path, res);
        return res;

    }

private:
    void generate(TreeNode *node, int sum, int &pathSum, vector<int> &path,vector<vector<int>> &res) {
        if (!node) {
            return;
        }

        pathSum += node->val;
        path.push_back(node->val);

        if (pathSum == sum && !node->left && !node->right) {
            res.push_back(path);
        }

        generate(node->left, sum, pathSum, path, res);
        generate(node->right, sum, pathSum, path, res);
        pathSum -= node->val;
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


    preOrderWithStack(&a);
    cout << endl;

    Solution solution;
    vector<vector<int>> res = solution.pathSum(&a, 22);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
