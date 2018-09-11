//
// Created by Insomnia on 2018/6/17.
//
#include <iostream>
#include <map>
#include <vector>

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //原链表, 地址到节点位置的map
        std::map<RandomListNode *, int> nodeMap;
        //新链表使用vector根据存储节点位置访问地址, 与上面用map映射不同
        std::vector<RandomListNode *> nodeVec;
        RandomListNode *ptr = head;
        int i = 0;
        while  (ptr) {
            nodeVec.push_back(new RandomListNode(ptr->label));
            nodeMap[ptr] = i;
            ptr = ptr->next;
            i++;
        }

        //新链表关系最后 push一个 0
        nodeVec.push_back(NULL);
        ptr = head;
        i = 0;

        while (ptr) {
            //链接vector node的指针
            nodeVec[i]->next  = nodeVec[i+1];
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
    //设置一个节点map， key为节点地址， value为模型
    std::map<RandomListNode *, int> nodeMap;

    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);

    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;

    nodeMap[&a] = 1;
    nodeMap[&b] = 2;
    nodeMap[&c] = 3;

    std::cout << "a.random " << nodeMap[a.random] << std::endl;
    std::cout << "b.random " << nodeMap[b.random] << std::endl;
    std::cout << "c.random " << nodeMap[c.random] << std::endl;
    return 0;
}