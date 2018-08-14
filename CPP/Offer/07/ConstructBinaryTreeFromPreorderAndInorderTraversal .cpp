// 
// Created by Insomnia on 18-8-14.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return generate(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* generate(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl >= pr || il >= ir) {
            return NULL;
        }
        int mid = preorder[pl];
        auto f = find(inorder.begin()+il, inorder.begin() +ir, mid);
        int dis = f - inorder.begin() - il;
        TreeNode *root = new TreeNode(mid);
        root->left = generate(preorder, pl + 1, pl + 1 + dis, inorder, il, il + dis);
        root->right = generate(preorder, pl + 1 + dis, pr, inorder, il + dis + 1, ir);
        return root;

    }
};

void preOrderStackTraverse(TreeNode *root) {
    if (!root){
        return;
    }
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != NULL) {
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

int main()  {
    int preNums[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inNums[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> preVec(&preNums[0], &preNums[8]);
    vector<int> inVec(&inNums[0], &inNums[8]);
    Solution solution;
    TreeNode *resNode = solution.buildTree(preVec, inVec);

    preOrderStackTraverse(resNode);

    return  0;
}