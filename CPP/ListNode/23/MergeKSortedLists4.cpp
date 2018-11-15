//
// @ClassName MergeKSortedLists4
// @Description TODO
// @Date 2018/11/15 上午9:49
// @Created by Insomnia
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


class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    };

private:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode tmp(0);
        ListNode *ptr = &tmp;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (l1) {
            ptr->next = l1;

        }

        if (l2) {
            ptr->next = l2;
        }

        return tmp.next;
    }
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
