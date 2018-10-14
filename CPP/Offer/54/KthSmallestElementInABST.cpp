// 
// Created by Insomnia on 18-10-14.
//同 leetcode 230
//Kth Smallest Element in a BST

#include <vector>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        vector<int> res;
        while (!s.empty() || p != NULL) {
            while (p) {
                s.push(p);
                p = p->left;
            }

            p = s.top();
            s.pop();

            res.push_back(p->val);
            p = p->right;
        }

        return res[k - 1];
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(6);
    TreeNode d(2);
    TreeNode e(4);
    TreeNode f(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    d.left = &f;

    Solution solution;

    cout << solution.kthSmallest(&a, 3) << endl;

    return 0;
}