// 
// Created by Insomnia on 18-10-14.
//

#include <vector>
#include <set>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

using namespace std;

class Solution {
public:
    ListNode *joinNode(ListNode *node1, ListNode *node2) {

        set<ListNode *> nodeSet;
        while (node1) {
            nodeSet.insert(node1);
            node1 = node1->next;
        }

        while (node2) {
            if (nodeSet.count(node2) > 0) {
                return node2;
            }
            node2 = node2->next;
        }
        return NULL;
    }

};

int main() {
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

    ListNode *res = sol.joinNode(&a1, &b1);
    cout << "Join node : " << res->val << endl;
    return 0;
}