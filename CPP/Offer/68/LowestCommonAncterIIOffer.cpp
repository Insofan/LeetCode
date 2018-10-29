// 
// @ClassName LowestCommonAncterIIOffer
// @Description leetcode 236 dfs做法
// @Date 18-10-29 下午11:50
// @Created by Insomnia
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return dfsHelper(root, p, q);
    }

private:
    TreeNode* dfsHelper(TreeNode * root, TreeNode *p, TreeNode *q) {
        if (root == p || root == q || root == NULL) {
            return root;
        }
        
        TreeNode *p1 = dfsHelper(root->left, p , q);
        TreeNode *p2 = dfsHelper(root->right, p, q);
        
        if (p1 && p2) {
            return root;
        } else {
            return p1 ? p1 : p2;
        }
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
    cout  << solution.lowestCommonAncestor(&a, &b, &c)->val << endl;
    cout  << solution.lowestCommonAncestor(&a, &b, &e)->val << endl;
    return 0;
}