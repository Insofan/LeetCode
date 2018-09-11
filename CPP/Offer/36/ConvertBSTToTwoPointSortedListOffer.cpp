// 
// Created by Insomnia on 18-9-11.
//

#include <iostream>
#include "../TreeNode.h"

class Solution {
public:
    TreeNode * convert(TreeNode *root) {
        TreeNode *lastNodeInList = NULL;
        helper(root, &lastNodeInList);
        TreeNode *headOfList = lastNodeInList;

        while (headOfList->left) {
            headOfList = headOfList->left;
        }
        return headOfList;
    }

private:
    void helper(TreeNode *root, TreeNode **lastNodeInList) {
        if (!root) {
            return;
        }

        TreeNode *current = root;
        if (root->left) {
            helper(current->left, lastNodeInList);
        }

        //修改指针指向
        current->left= *lastNodeInList;

        if (*lastNodeInList) {
            (*lastNodeInList)->right = current;
        }
        *lastNodeInList = current;

        //修改完毕

        if (current->right) {
            helper(current->right, lastNodeInList);
        }
    }
};