// 
// @ClassName ReverseKthNode
// @Description 链表中倒数第k个节点
// @Date 18-12-4 下午9:06
// @Created by Insomnia
//


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

using namespace std;

class Solution {
public:
    ListNode *revKthNode(ListNode* head, int k) {
            ListNode *fir = head;
            ListNode *sec = head;
            for (int i = 1; i <=k; i++) {
                if (fir) {
                   fir = fir->next;
                } else {
                    return NULL;
                }
            }

            while  (fir) {
                sec = sec->next;
                fir = fir->next;
            }

            return sec;
        }
private:

};

int main() {
    ListNode a= ListNode(1);
    ListNode b= ListNode(2);
    ListNode c= ListNode(3);
    ListNode d= ListNode(4);
    ListNode e= ListNode(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    Solution sol = Solution();
    ListNode *res = sol.revKthNode(&a, 3);
    cout << res->val << endl;

    return 0;
}
