//
// Created by Insomnia on 2018/6/13.
//
/**
 * leetcode 206 链表逆序
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 构造函数 ListNode(int x) : val(x), next(NULL) {}
 */

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
        ListNode *newHead = NULL;
        while (head){
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
    
    ListNode *secReversList(ListNode *head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
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
    //head = solution.reverseList(head);
    head = solution.secReversList(head);
    while (head) {
        printf("val %d\n", head->val);
        head = head->next;
    }

    return 0;
}

