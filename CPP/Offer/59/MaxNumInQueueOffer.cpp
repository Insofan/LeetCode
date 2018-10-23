//
// @ClassName MaxNumInQueueOffer
// @Description 求一个队列中的最大值
// @Date 2018/10/23 下午3:12
// @Created by Insomnia
//

#include <stdio.h>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class MonotionQueue {
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

    int max() {
        return _data.front();
    }

private:
    deque<int> _data;
};

class Solution {
public:
    int maxNumInQueue(vector<int> &vec) {
        MonotionQueue q;

        for (int i = 0; i < vec.size(); ++i) {
            q.push(vec[i]);
        }
        return q.max();
    }
};

int main() {
    int         a[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vec(&a[0], &a[8]);
    Solution    solution;
    int res = solution.maxNumInQueue(vec);
    cout << res << endl;
    return 0;
}
