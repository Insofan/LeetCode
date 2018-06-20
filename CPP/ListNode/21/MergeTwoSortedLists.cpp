//
// Created by Insomnia on 2018/6/20.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode tempHead(0);
        ListNode *ptr = &tempHead;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (l1) {
            ptr->next = l1;
        }

        if (l2) {
            ptr->next = l2;
        }

        return tempHead.next;
    }
};


int main() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(4);

    ListNode b1(1);
    ListNode b2(3);
    ListNode b3(4);

    a1.next = &a2;
    a2.next = &a3;

    b1.next = &b2;
    b2.next = &b3;

    Solution sol;
    ListNode *head = sol.mergeTwoLists(&a1, &b1);

    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
