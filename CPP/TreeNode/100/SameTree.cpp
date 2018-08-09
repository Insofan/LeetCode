//
// Created by Insomnia on 2018/8/9.
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

void preorderBinaryTree(int layer, TreeNode *node) {
    if (!node) {
        return;
    }

    for (int i = 0; i < layer; ++i) {
        cout << "--";
    }
    cout << node->val << endl;
    preorderBinaryTree(layer + 1, node->left);
    preorderBinaryTree(layer + 1, node->right);
}

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        vector<int> vec1;
        generate(p, vec1);

        vector<int> vec2;
        generate(q, vec2);

        if (vec1.size() != vec2.size()) {
            return false;
        }

        for (int i = 0; i < vec1.size(); ++i) {
            if (vec1[i] != vec2[i]) {
                return false;
            }
        }
        return true;
    }

private:
    void generate(TreeNode *node, vector<int> &vec) {
        if (!node) {
            vec.push_back(-1);
            return;
        }
        vec.push_back(node->val);
        generate(node->left, vec);
        generate(node->right, vec);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(1);

    a.left = &b;
    a.right = &c;

    TreeNode a2(1);
    TreeNode b2(2);
    TreeNode c2(1);
//    TreeNode d2(3);

    a2.left = &b2;
    a2.right = &c2;
//    b2.left = &d2;
//    a2.left = NULL;
//    a2.right= &b2;

    Solution solution;
    cout << boolalpha << solution.isSameTree(&a, &a2) << endl;

    return 0;
}
