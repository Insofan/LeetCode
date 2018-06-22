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
//    for (int i = 0; i < ; ++i) {
//
//    }
    return NULL;
}

class Solution {
    ListNode * mergeKLists(std::vector<ListNode *> lists){
        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() == 2) {
            return  mergeTwoLists(lists[0], lists[1]);
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

        ListNode *l1 = mergeKLists(*sub1List[0]);
        ListNode *l2 = mergeKLists(*sub2List[0]);
        return mergeTwoLists(l1, l2);
    };
};
