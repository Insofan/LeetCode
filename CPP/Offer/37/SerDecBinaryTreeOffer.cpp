//
// Created by Insomnia on 2018/9/13.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

using namespace std;

class Solution {
public:
     string seralBinaryTree(TreeNode *root) {
         ostringstream out;
         serHelper(root, out);
         return out.str();
     }

     TreeNode *decodeBinaryTree (string inStr) {
        istringstream data(inStr);
         return decodeHelper(data);
     }

private:
    void serHelper(TreeNode *node, ostringstream &out) {
         if (!node) {
             out << "# ";
             return;
         }

         out << node->val << " ";
         serHelper(node->left, out);
         serHelper(node->right, out);
     }

     TreeNode *decodeHelper(istringstream &data) {
         string val;
         data >> val;

         if (val == "#") {
             return nullptr;
         }

         TreeNode *root = new TreeNode(stoi(val));
         root->left = decodeHelper(data);
         root->right = decodeHelper(data);

         return root;
     }
};


void preOrder(TreeNode *root) {
    TreeNode *ptr = root;
    stack<TreeNode *> s;

    while (!s.empty() || ptr != NULL) {

        while (ptr) {
            s.push(ptr);
            cout << ptr->val << " ";
            ptr = ptr->left;
        }

        ptr = s.top();
        s.pop();
        ptr = ptr->right;
    }

    cout << endl;

}

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

    preOrder(&a);

    Solution solution;
    string str = solution.seralBinaryTree(&a);

    cout << str << endl;

    TreeNode *res = solution.decodeBinaryTree(str);

    preOrder(res);

    return 0;
}
