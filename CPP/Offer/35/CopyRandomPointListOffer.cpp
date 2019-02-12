//
// Created by Insomnia on 2018/9/11.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct RandomListNode {
    int val;
    RandomListNode *next, *random;

    RandomListNode(int x): val(x), next(NULL), random(NULL){}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, int> nodeMap;
        vector<RandomListNode *> nodeVec;

        RandomListNode *ptr = head;
        int i = 0;

        while (ptr) {
            nodeVec.push_back(new RandomListNode(ptr->val));
            nodeMap[ptr] = i;
            ptr = ptr->next;
            i++;
        }

        nodeVec.push_back(NULL);
        ptr = head;
        i = 0;

        while (ptr) {
            nodeVec[i]->next = nodeVec[i+1];

            if (ptr->random) {
                int id = nodeMap[ptr->random];
                nodeVec[i]->random = nodeVec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return nodeVec[0];

    }
};


int main() {

    map<RandomListNode *, int> nodeMap;

    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);

    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &b;

    nodeMap[&a] = 1;
    nodeMap[&b] = 2;
    nodeMap[&c] = 3;

    Solution solution;
    RandomListNode *res = solution.copyRandomList(&a);

    while (res) {
        cout << res->val << " ";
        if (res->random) {
            cout << "random: " << res->random;
        }
        res = res->next;
        cout << endl;
    }

    cout << endl;
    return 0;
}
