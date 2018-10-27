// 
// @ClassName LastInCircleOffer
// @Description 每次从圆圈中删除第m个数字, 约瑟夫环问题
// @Date 18-10-27 上午10:22
// @Created by Insomnia
//

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

/* structure for a node in circular
   linked list
*/
struct Node {
    int data;
    Node *next;
};

//To create a new node of circular
Node *newNode(int data) {
    Node *tmp = new Node;
    tmp->next = tmp;
    tmp->data = data;
}

class Solution1 {
public:
    /**
     * 这是约瑟夫环问题
     * @param n 一共有n个人
     * @param k 从第k个人开始报数
     * @param m 从报数开始第几个人出列
     * @return 因为这里是从0开始, 一般都从1开始
     */
    int lastNumbInCircle(int n, int m) {
        /**
         * 构造唤醒链表
         */
        Node *head = newNode(0);
        Node *pre = head;
        for (int i = 1; i < n ; ++i) {
            pre->next = newNode(i);
            pre = pre->next;
        }
        pre->next = head;

        /*
         * 计算最后一个node
         */
        Node *ptr1 = head;
        Node *ptr2 = head;
        while (ptr1->next != ptr1) {
            /*
             * 找第m个node
             */
            int count = 1;
            while (count != m) {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
                count++;
            }

            /*
             * 删除节点
             */
            ptr2->next = ptr1->next;
            ptr1 = ptr2->next;
        }

        return ptr1->data;
    }
};

class Solution2 {
public:
    int lastNumbInCircle(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }

        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
};

int main() {

     Solution1 solution1;
     cout << solution1.lastNumbInCircle(5, 3) << endl;
    Solution2 solution2;
    cout << solution2.lastNumbInCircle(5, 3) << endl;

    return 0;
}