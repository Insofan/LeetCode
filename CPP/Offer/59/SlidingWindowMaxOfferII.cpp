//
// @ClassName SlidingWindowMaxOfferII
// @Description leetcode 239 用单调队列做
// @Date 2018/10/23 下午2:57
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class MonotonicQueue {
public:

    void push(int x) {
        while (!_data.empty() && x > _data.back()) {
            _data.pop_back();
        }
        _data.push_back(x);
    }

    void pop() {
        _data.pop_front();
    }

    int max()const { return _data.front();}
private:
    deque<int> _data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &vec, int k) {
        MonotonicQueue q;
        vector<int> res;

        for (int i = 0; i < vec.size(); i++) {
            q.push(vec[i]);
            if (i - k + 1 >= 0) {
                res.push_back(q.max());
                //需要更新front,
                if (vec[i - k + 1] == q.max()) {
                    q.pop();
                }
            }
        }
        return res;
    }
};


int main() {
    int         a[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vec(&a[0], &a[8]);
    Solution    solution;
    vector<int> res = solution.maxSlidingWindow(vec, 3);
    for (auto   val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
