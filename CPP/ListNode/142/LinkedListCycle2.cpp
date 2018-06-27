//
// Created by Insomnia on 2018/6/15.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow) {
                meet = fast;
                break;
            }
        }

        if (meet == NULL) {
            return NULL;
        }

        while (head && meet) {
            if (meet == head) {
                return head;
            }

            meet = meet->next;
            head = head->next;
        }
        return NULL;
    }
};

int main() {

    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);
    ListNode a6(6);
    ListNode a7(7);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    a6.next = &a7;
    a7.next = &a3;

    Solution solution;
    ListNode *head = solution.detectCycle(&a1);
    std::cout << head->val << std::endl;
    return 0;
}
