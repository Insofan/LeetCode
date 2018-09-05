//
// Created by Insomnia on 2018/9/5.
//

#include <stdio.h>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr = head;
        while (ptr) {
            if (ptr->next && (ptr->val == ptr->next->val)) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

int main() {

    return 0;
}
