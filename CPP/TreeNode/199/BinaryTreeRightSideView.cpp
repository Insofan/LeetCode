//
// Created by Insomnia on 2018/7/13.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> view;
        //宽度优先搜索队列
        queue<pair<TreeNode *, int>> Q;
        if (root) {
            Q.push(make_pair(root, 0));
        }

        while (!Q.empty()) {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if (view.size() == depth) {
                view.push_back(node->val);
            } else {
                view[depth] = node->val;
            }

            if (node->left) {
                Q.push(make_pair(node->left, depth + 1));
            }

            if (node->right) {
                Q.push(make_pair(node->right, depth + 1));
            }
        }
        return view;
    }
private:

};

int main() {

    return 0;
}
