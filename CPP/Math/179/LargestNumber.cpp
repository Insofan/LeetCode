//
// @ClassName Largest
// @Description TODO
// @Date 2019/4/3 9:03 AM
// @Created by Insomnia
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool myCmp(int a, int b) {
    string tmp("");
    string strA = to_string(a);
    string strB = to_string(b);

    string ab = strA + strB;
    string ba = strB + strA;

    if (ab > ba) {
        return true;
    } else {
        return false;
    }
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myCmp);
        string res = "";
        for (auto val : nums) {
            res += to_string(val);
        }

        return res[0] == '0' ? "0" : res;
    }


};

int main() {
    vector<int> vec = {123, 1, 6};
    Solution sol;
    sol.largestNumber(vec);
    return 0;
}
