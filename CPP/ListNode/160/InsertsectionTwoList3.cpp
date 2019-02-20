//
// @ClassName InsertsectionTwoList3
// @Description TODO
// @Date 2019/2/20 5:30 PM
// @Created by Insomnia
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;

        while (cur1 != cur2) {
            cur1 = cur1 ? cur1->next : head2;
            cur2 = cur2 ? cur2->next : head1;
        }

        return cur1;
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
    ListNode *res = sol.getIntersectionNode(&a1, &b1);
//    std::cout << res->val << std::endl;
    printf("%d\n", res->val);
    return 0;
}
