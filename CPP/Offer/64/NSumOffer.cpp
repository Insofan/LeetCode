// 
// @ClassName NSumOffer
// @Description 不用条件循环语句, 乘法公式求1 到 n的和
// @Date 18-10-27 下午7:28
// @Created by Insomnia
//
#include <iostream>

using namespace std;

class Solution {
public:
    int sumSolution(int n) {
        int ans = n;
        ans && (ans += sumSolution(n - 1));
        return ans;
    }
};

int main() {
    int n = 100;

    //用&&的短路性质, 为false时 不会&&
     Solution solution;
     cout << solution.sumSolution(n) << endl;

    return 0;
}


