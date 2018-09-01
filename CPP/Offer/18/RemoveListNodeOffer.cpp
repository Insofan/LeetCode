// 
// Created by Insomnia on 18-9-1.
//
//leetcode 237 203

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

void printListNode(ListNode *node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
class Solution {
public:
    ListNode* deleteNode(ListNode **head, ListNode *deleteNode) {
        ListNode *preHead = new ListNode(0);
        preHead->next = *head;
        ListNode *cur = preHead;
        while (cur) {
            if (cur->next && cur->next == deleteNode) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return preHead->next;
    }

    ListNode *secDeleteNode(ListNode *head, ListNode*deleteNode) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *cur = preHead;
        while (cur) {
            if (cur->next && cur->next == deleteNode) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return preHead->next;
    }
};

int main () {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    printListNode(&a);

    Solution solution;
    ListNode *head = &a;
    /*
    ListNode *res = solution.deleteNode(&head, &a);
    printListNode(res);
    res = solution.deleteNode(&res, &c);
    printListNode(res);
    res = solution.deleteNode(&res, &e);
    printListNode(res);
     */

    ListNode *res = solution.secDeleteNode(&a, &a);
    printListNode(res);
    res = solution.secDeleteNode(res, &c);
    printListNode(res);
    res = solution.secDeleteNode(res, &e);
    printListNode(res);
    return 0;
}