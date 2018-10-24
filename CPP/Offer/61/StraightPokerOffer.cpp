// 
// @ClassName StraightPokerOffer
// @Description 判断5张牌是不是顺子
// @Date 18-10-24 下午11:25
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int x, int y) {
    return x < y;
}

class Solution {
public:
    bool isStraight(vector<int> vec) {
        if (vec.size() != 5) {
            return false;
        }

        //0代表大小王, 可以代替任何数字
        sort(vec.begin(), vec.end(), [](int x, int y) {
            return x < y;
        });

        int numZero = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 0) {
               numZero++;
            }
        }

        int gap = 0;
        for (int i = numZero; i < vec.size() - 1; i++) {
            //有对子, 肯定不能为顺子
            if (vec[i] == vec[i + 1]) {
                return false;
            }
            //算gap
            gap += vec[i + 1] - vec[i] - 1;
        }

        //gap > zero 个数 则 不是顺子
        return  gap > numZero ? false : true;
    }
};


int main() {
    vector<int> data{ 5,7,6,0,4 };
    Solution solution;
    cout << boolalpha << solution.isStraight(data) << endl;
    return 0;
}
