// 
// Created by Insomnia on 2018/7/12.
//

//用vector 完成， 不够优秀 但能完成
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
    void flatten(TreeNode *root) {
        vector<TreeNode *> nodeVec;
        preOrder(root, nodeVec);
        for (int i = 1; i < nodeVec.size(); ++i) {
            nodeVec[i-1]->left = NULL;
            nodeVec[i-1]->right= nodeVec[i];
        }

    }

private:
    void preOrder(TreeNode *node, vector<TreeNode *> &nodeVec) {
        if (!node) {
            return;
        }

        nodeVec.push_back(node);
        preOrder(node->left, nodeVec);
        preOrder(node->right, nodeVec);
    }
};

int main() {

}