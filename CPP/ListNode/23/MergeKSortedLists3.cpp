//
// Created by Insomnia on 2018/6/23.
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

ListNode *mergeTwoLists(ListNode *listOne, ListNode *listTwo) {
    //考察21题目知识点
    ListNode tempList(0);
    ListNode *ptr = &tempList;

    while (listOne && listTwo) {
        if (listOne->val < listTwo->val) {
            ptr->next = listOne;
            listOne = listOne->next;
        } else {
            ptr->next = listTwo;
            listTwo = listTwo->next;
        }
        ptr = ptr->next;
    }

    if (listOne) {
        ptr->next = listOne;
    }

    if (listTwo) {
        ptr->next = listTwo;
    }

    return tempList.next;

}

class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size() / 2;

        std::vector<ListNode *> sub1List;
        std::vector<ListNode *> sub2List;
        for (int i = 0; i < mid; ++i) {
            sub1List.push_back(lists[i]);
        }

        for (int j = mid; j < lists.size(); ++j) {
            sub2List.push_back(lists[j]);
        }

        ListNode *l1 = mergeKLists(sub1List);
        ListNode *l2 = mergeKLists(sub2List);
        return mergeTwoLists(l1, l2);
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