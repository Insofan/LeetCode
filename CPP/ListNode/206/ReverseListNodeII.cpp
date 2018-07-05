//
// Created by Insomnia on 2018/7/5.
//



#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode tempNode(0);

        while (head) {
            ListNode *next = head->next;
            head->next = tempNode.next;
            tempNode.next = head;
            head = next;
        }
        return tempNode.next;
    }
};



int main(int argc, char *argv[]) {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head;
    head = &a;

    Solution solution;
    head = solution.reverseList(head);
    while (head) {
        printf("val %d\n", head->val);
        head = head->next;
    }

    return 0;
}
