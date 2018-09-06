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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode preHead = ListNode(INT32_MIN);
        preHead.next = head;
        ListNode *ptr = &preHead;
        while (ptr) {
            if (ptr->next && (ptr->next->val == val)) {
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
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    printListNode(&a);

    Solution solution;
    ListNode *head = &a;


    ListNode *res = solution.removeElements(&a, 1);
    printListNode(res);
    res = solution.removeElements(res, 5);
    printListNode(res);
    res = solution.removeElements(res, 3);
    printListNode(res);

    return 0;
}
