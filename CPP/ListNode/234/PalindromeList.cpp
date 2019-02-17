// 
// @ClassName PalindromeList
// @Description TODO
// @Date 19-2-17 下午10:25
// @Created by Insomnia
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool isPalindrome(ListNode* head) {

        ListNode *copyHead = new ListNode(0);
        ListNode *copyCurent = copyHead;
        ListNode *tmpHead = head;

        while (tmpHead) {
            copyCurent->next = new ListNode(tmpHead->val);
            copyCurent = copyCurent->next;
            tmpHead = tmpHead->next;
        }
        ListNode *reverHead = reverseList(copyHead->next);

        while (head) {
            if (head->val != reverHead->val) {
                return false;
            }
            head = head->next;
            reverHead = reverHead->next;
        }

        return true;
    }

private:
    ListNode * reverseList(ListNode *head) {
        ListNode *newHead = NULL;

        while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};


int main() {

    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(1);

    a1.next = &a2;
    a2.next = &a3;

    ListNode b1(1);
    ListNode b2(2);
    ListNode b3(3);

    b1.next = &b2;
    b2.next = &b3;

    Solution sol;
    cout << boolalpha << sol.isPalindrome(&a1) << endl;
    cout << boolalpha << sol.isPalindrome(&b1) << endl;

    return 0;
}