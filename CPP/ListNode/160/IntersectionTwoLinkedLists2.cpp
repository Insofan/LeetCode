//
// Created by Insomnia on 2018/6/14.
//
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int getListLength(ListNode *list) {
    int len = 0;
    while (list) {
        len++;
        list = list->next;
    }
    return len;
}

ListNode *forwordLongList(int longLen, int shortLen, ListNode *head) {
    int delta = longLen - shortLen;
    while (head && delta) {
        head = head->next;
        delta--;
    }
    return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLen = getListLength(headA);
        int bLen = getListLength(headB);
        if (aLen > bLen) {
            headA = forwordLongList(aLen, bLen, headA);
        } else {
            headB = forwordLongList(bLen, aLen, headB);
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode b1(4);
    ListNode b2(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &c1;

    Solution sol;
    ListNode *res = sol.getIntersectionNode(&a1, &b1);
    std::cout << res->val << std::endl;

    return 0;
}