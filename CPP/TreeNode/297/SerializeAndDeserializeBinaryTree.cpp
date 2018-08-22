//
// Created by Insomnia on 2018/8/22.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<vector<int>> res;
        layerTravavse(root, 0, res);
        res.pop_back();
//        for (int i = 0; i < res.size(); ++i) {
//            for (int j = 0; j < res[i].size(); ++j) {
//               cout << res[i][j] << " ";
//            }
//            cout << endl;
//        }
        string str;
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                str += res[i][j];
            }
        }
        return str;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }

private:
    void layerTravavse(TreeNode *node, int level, vector<vector<int>> &res) {
        if (res.empty() || res.size() - 1 < level) {
            res.push_back(vector<int> ());
        }

        if (!node) {
            res[level].push_back(-1);
            return;
        }

        res[level].push_back(node->val);

        layerTravavse(node->left, level+1, res);
        layerTravavse(node->right, level+1, res);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);

    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;

    Codec codec;
    codec.serialize(&a);

    return 0;
}
