//
// Created by Insomnia on 2018/8/14.
//


#include <iostream>
#include <stdlib.h>
#ifndef CPP_TREENODE_H
#define CPP_TREENODE_H
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x):val(x), left(NULL), right(NULL){}
};

#endif //CPP_TREENODE_H
