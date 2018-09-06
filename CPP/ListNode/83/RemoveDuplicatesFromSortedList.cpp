//
// Created by Insomnia on 2018/9/5.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int      val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode preHead = ListNode(INT32_MIN);
        preHead.next = head;
        ListNode *ptr = &preHead;
        while (ptr) {
            if (ptr->next && ptr->val == ptr->next->val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }

        return preHead.next;
    }
};

void printListNode(ListNode *node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {

    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(3);
    ListNode e(3);
    ListNode f(3);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    ListNode *head = &a;
    printListNode(head);

    Solution solution;


    ListNode *res = solution.deleteDuplicates(head);
    printListNode(res);


    return 0;
}
