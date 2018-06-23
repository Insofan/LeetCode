//
// Created by Insomnia on 2018/6/22.
//

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

bool cmp(ListNode *x, ListNode *y) {
    return x->val < y->val;
}



class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        vector<ListNode *> nodeVec;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode *head = lists[i];
            while (head) {
                nodeVec.push_back(head);
                head = head->next;
            }
        }

        if (nodeVec.size() == 0) {
            return NULL;
        }

        std::sort(nodeVec.begin(), nodeVec.end(), cmp);
        for (int j = 1; j < nodeVec.size(); ++j) {
           nodeVec[j-1]->next = nodeVec[j];
        }
        nodeVec[nodeVec.size() - 1]->next = NULL;
        return nodeVec[0];
    };
};

int main() {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);

    a.next = &b;
    b.next = &c;

    d.next = &e;
    e.next = &f;

    g.next = &h;

    vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);

    Solution sol;

    ListNode *head = sol.mergeKLists(lists);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}