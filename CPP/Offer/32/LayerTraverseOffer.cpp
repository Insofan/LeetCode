// 
// Created by Insomnia on 18-9-9.
//


#include <iostream>
#include "../TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> layerTraverse(TreeNode *root) {
        vector<int> res;
        vector<vector<int>> layerVec;
        int layer = 0;
        generate(root, layer, layerVec);
        for (int i = 0; i < layerVec.size(); ++i) {
            for (int j = 0; j < layerVec[i].size(); ++j) {
                res.push_back(layerVec[i][j]);
            }
        }

        return res;
    }

    vector<vector<int>> layerTraverseTwo(TreeNode *root) {
        vector<vector<int>> layerVec;
        int layer = 0;
        generate(root, layer, layerVec);

        return layerVec;
    }

private:
    void generate(TreeNode *node, int layer, vector<vector<int>> &layerVec) {
        if (!node) {
            return;
        }
        layerVec.push_back(vector<int>());
        layerVec[layer].push_back(node->val);
        generate(node->left, layer + 1, layerVec);
        generate(node->right, layer + 1, layerVec);
    }
};

int main() {
    TreeNode a(8);
    TreeNode b(6);
    TreeNode c(10);
    TreeNode d(5);
    TreeNode e(7);
    TreeNode f(9);
    TreeNode g(11);

    a.left = &b;
    b.left = &d;
    b.right = &e;
    a.right = &c;
    c.left = &f;
    c.right = &g;

    Solution solution;
    vector<int> res = solution.layerTraverse(&a);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    cout << "layer vec ------------" << endl;

    vector<vector<int>> res2 = solution.layerTraverseTwo(&a);

    for (int i = 0; i < res2.size(); ++i) {
        for (int j = 0; j < res2[i].size(); ++j) {
            cout << res2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}