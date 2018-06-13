//
// Created by Insomnia on 2018/6/13.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int changeLen = n - m + 1;
        ListNode *preHead = NULL;
        ListNode *result = head;
        while (head && --m) {
            preHead = head;
            head = head->next;
        }
        ListNode *modifyListTail = head;

        ListNode *newHead = NULL;
        while (head && changeLen) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            changeLen--;
        }

        modifyListTail->next = head;

        if (preHead) {
            preHead->next = newHead;
        } else {
            result = newHead;
        }
        return result;
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
    e.next = NULL;


    Solution solution;
    ListNode *head = solution.reverseBetween(&a, 2, 4);
    while (head) {
        printf("val %d\n", head->val);
        head = head->next;
    }

    return 0;
}