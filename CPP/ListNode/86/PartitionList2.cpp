//
// Created by Insomnia on 2018/6/19.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode lessNode(0);
        ListNode moreNode(0);

        ListNode *lessPtr = &lessNode;
        ListNode *morePtr = &moreNode;

        while (head) {
            if (head->val < 3) {
                lessPtr->next = head;
                lessPtr = head;
            } else {
                morePtr->next = head;
                morePtr = head;
            }
            head = head->next;
        }

        lessPtr->next = moreNode.next;
        morePtr->next = NULL;

        return lessNode.next;
    }
};


int main() {
    ListNode a1(1);
    ListNode a2(4);
    ListNode a3(3);
    ListNode a4(2);
    ListNode a5(5);
    ListNode a6(2);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;

    Solution sol;
    ListNode *head = sol.partition(&a1, 3);

    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }


    return 0;
}
