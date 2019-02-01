// 
// @ClassName AddStrings
// @Description TODO
// @Date 19-2-1 下午10:40
// @Created by Insomnia
//

// 模拟大数相加
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        string res;
        while (i >= 0 || j >= 0 || carry) {
            long sum = 0;
            if (i >= 0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            carry = sum / 10;
            sum %= 10;
            res += to_string(sum);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string string1 = "123111111";
    string string2 = "456111111";
    Solution sol;

    cout << sol.addStrings(string1, string2) << endl;
    return 0;
}