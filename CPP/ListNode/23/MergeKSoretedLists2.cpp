//
// Created by Insomnia on 2018/6/22.
//

//把所有节点放到vector里面， 然后排序, 然后链接

#include<iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

bool cmp(ListNode *x, ListNode *y) {
    return x->val < y->val;
}


int main() {
    ListNode a1(3);
    ListNode a2(2);
    ListNode a3(5);
    ListNode a4(0);

    vector<ListNode *> vec;
    vec.push_back(&a1);
    vec.push_back(&a2);
    vec.push_back(&a3);
    vec.push_back(&a4);

    sort(vec.begin(), vec.end(),cmp);

    for (int i = 0; i < vec.size(); ++i) {
       cout << vec[i]->val << " ";
    }
    cout << endl;

    return 0;
}