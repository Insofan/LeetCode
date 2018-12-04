// 
// @ClassName AdjustArr
// @Description 调整数组顺序使奇数位于偶数前面
// @Date 18-12-4 下午8:31
// @Created by Insomnia
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> adjustArr(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                _oddQ.push(arr[i]);
            } else {
                _evenQ.push(arr[i]);
            }
        }
        cout << "odd size : " << _oddQ.size() << endl;
        cout << "even size : " << _evenQ.size() << endl;

        vector<int> res;
        int i = 0;
        while (_oddQ.size()) {
            res.push_back(_oddQ.front());
            _oddQ.pop();
        }

        while (_evenQ.size()) {
            res.push_back(_evenQ.front());
            _evenQ.pop();
        }

        return res;
    }
private:
   queue<int> _oddQ;
    queue<int> _evenQ;
};

int main() {
    vector<int> arr1 = {1, 2, 3, 3, 4, 5};

    Solution sol = Solution();
    vector<int> res = sol.adjustArr(arr1);
    for (int i = 0; i <res.size(); i++) {
       cout <<res[i] << endl;
    }
    return 0;
}