//
// Created by Insomnia on 2018/6/14.
//

//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include <iostream>
#include <set>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //set 复杂度 n lgn
        std::set<ListNode *> nodeSet;
        while (headA) {
            nodeSet.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (nodeSet.find(headB) != nodeSet.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};


int main(int argc, char *argv[]) {
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);

    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;

    Solution sol;
    ListNode *res = sol.getIntersectionNode(&a1, &b1);
//    std::cout << res->val << std::endl;
    printf("%d\n", res->val);

    return 0;
}
