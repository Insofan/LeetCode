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
    ListNode *reverseList(ListNode *node) {
        ListNode *tempNode = NULL;
        while (node) {
            ListNode *next = node->next;
            node->next = tempNode;
            tempNode =node;
            node = next;
        }

        return tempNode;
    }
};

int main () {
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

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    Solution solution;
    head = solution.reverseList(&a);
    while (head) {
        printf("val %d\n", head->val);
        head = head->next;
    }

    return  0;
}