//
// Created by Insomnia on 2018/8/21.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        int level = 0;
        generate(root, level, res);
        //翻转
        reverse(res.begin(), res.end());
        return res;
    }


private:
    void generate(TreeNode *node, int level, vector<vector<int>> &res) {
        if (!node) {
            return;
        }

        if ( res.empty() || res.size() < level + 1) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        generate(node->left, level+1, res);
        generate(node->right, level+1, res);
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(17);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    Solution solution;
    vector<vector<int>> res = solution.levelOrderBottom(&a);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
