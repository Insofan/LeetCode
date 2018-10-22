// 
// @ClassName SlidingWindowMaximumOffer
// @Description Leetcode 239 Sliding Window Maximum
// @Date 18-10-22 下午10:24
// @Created by Insomnia
//

/*
 *

 #if ($HEADER_COMMENTS)
//
// @ClassName ${NAME}
// @Description TODO
// @Date ${DATE} ${TIME}
// @Created by Insomnia
#if ($ORGANIZATION_NAME && $ORGANIZATION_NAME != "")
// Copyright (c) $YEAR ${ORGANIZATION_NAME}#if (!$ORGANIZATION_NAME.endsWith(".")).#end All rights reserved.
#end
//
#end

 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> slideWindowMax(vector<int> &vec, int k) {
        vector<int> res;
        deque<int> dq;

        //所有操作都是用来维护一个单调队列, monotonic queue
        for (int i = 0; i < vec.size(); i++) {
            //当dq元素大于窗口, 移除
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            //维护dq的递减
            //不为空, 且取出元素大于最后一个元素
            while (!dq.empty() && vec[dq.back()] < vec[i]) {
                dq.pop_back();
            }

            //插入
            dq.push_back(i);
            //当到第k个元素才会开始放入结果
            if (i >= k - 1) {
                res.push_back(vec[dq.front()]);
            }
        }
        return res;
    }

    vector<int> bruteVer(vector<int> &vec, int k) {
        vector<int> res;
        for (int i = k - 1; i <vec.size() ; i++) {
            res.push_back(*max_element(vec.begin() + i - k + 1, vec.begin() + i + 1));
        }
        return res;
    }
};

int main() {
    int a[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vec(&a[0], &a[8]);
    Solution solution;
    vector<int> res = solution.slideWindowMax(vec, 3);
   // vector<int> res = solution.bruteVer(vec, 3);
    for (auto val : res) {
        cout << val  << " ";
    }
    cout << endl;
    return 0;
}
