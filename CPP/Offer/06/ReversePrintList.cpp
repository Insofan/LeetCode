// 
// Created by Insomnia on 18-8-12.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

void printNode(ListNode *root) {
    while  (root) {
        cout <<root->val << " ";
        root=root->next;
    }
    cout << endl;
}

class Solution {
public:
    void reversePrintList(ListNode *root) {
        ListNode *node = NULL;
        while (root) {
            ListNode *tempNode = root->next;
            root->next = node;
            node = root;
            root = tempNode;
        }
        printNode(node);

    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode *node = &a;
    printNode(node);

    Solution solution;
    solution.reversePrintList(&a);

    return  0;
}