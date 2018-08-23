//
// Created by Insomnia on 2018/8/22.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

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
    string serialize(TreeNode *root) {
        ostringstream res;

        serPreorderTravase(root, res);

        return res.str();

    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream inStr(data);

        return desPreorderTravase(inStr);
    }

private:
    void serPreorderTravase(TreeNode *node, ostringstream &res) {
        if (!node) {
            res << "# ";
            return;
        }
        res << node->val << " ";
        serPreorderTravase(node->left, res);
        serPreorderTravase(node->right, res);

    }

    TreeNode *desPreorderTravase(istringstream &str) {
        string val;
        str >> val;
        if (val == "#") {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(val));
        root->left = desPreorderTravase(str);
        root->right = desPreorderTravase(str);

        return root;
    }
};

void preorderTra(TreeNode *node) {
    if (!node) {
        return;;
    }

    cout << node->val << " ";

    preorderTra(node->left);
    preorderTra(node->right);

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

    Codec codec;
//    cout <<codec.serialize(&a) << endl;
    preorderTra(codec.deserialize(codec.serialize(&a)));
    cout << endl;

    return 0;
}
