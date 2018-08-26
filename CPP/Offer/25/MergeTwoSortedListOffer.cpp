// 
// Created by Insomnia on 18-8-26.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode tempNode(0);
        ListNode *ptr = &tempNode;

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

        ptr->next = l1 ? l1 : l2;
        return tempNode.next;
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
    ListNode *head = sol.mergeList(&a1, &b1);

    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    return  0;
}