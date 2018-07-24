//
// Created by Insomnia on 2018/7/24.
// 有问题 输出乱码

#include <iostream>
#include <vector>
#include <string>

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
        string data;
        BST_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }

        vector<TreeNode *> nodeVec;
        int val = 0;

        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == '#') {
                nodeVec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + data[i] + '0';
            }
        }

        for (int j = 1; j < nodeVec.size(); j++) {
            BST_insert(nodeVec[0],nodeVec[j]);
        }
        return nodeVec[0];
    }

private:
    void changeIntToString(int val, string &strVal) {
        string temp;
        while (val) {
            temp += val % 10 - '0';
            val = val / 10;
        }

        for (int i = temp.length() - 1; i >= 0; i--) {
            strVal += temp[i];
        }
        strVal += '#';
    }

    void BST_preorder(TreeNode *node, string &data) {
        if (!node) {
            return;;
        }

        string strVal;
        changeIntToString(node->val, strVal);
        data += strVal;

        BST_preorder(node->left, data);
        BST_preorder(node->right, data);
    }

    void BST_insert(TreeNode *node, TreeNode *insertNode) {
        if (insertNode->val < node->val) {
            if (node->left) {
                BST_insert(node->left, insertNode);
            } else {
                node->left = insertNode;
            }
        } else {
            if (node->right) {
                BST_insert(node->right, insertNode);
            } else {
                node->right = insertNode;
            }
        }
    }
};

void preorderCout(TreeNode *node, int layer) {
    if (!node) {
        return;
    }

    for (int i = 0; i < layer; ++i) {
        cout << "--";
    }
    cout << node->val << endl;
    preorderCout(node->left, layer + 1);
    preorderCout(node->right, layer + 1);
}

int main() {
    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left  = &f;

    Codec sol;
    string data = sol.serialize(&a);
    cout << data.c_str() << endl;
    TreeNode *root = sol.deserialize(data);
    preorderCout(root, 0);
    return 0;
}
