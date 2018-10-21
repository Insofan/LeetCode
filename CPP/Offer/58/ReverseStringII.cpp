// 
// @ClassName ReverseStringII
// @Description Leetcode 541  Reverse String II
// @Date 18-10-21 下午10:22
// @Created by Insomnia
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s, int n) {
        reverseStr(s, 0, n - 1);
        reverseStr(s, n, s.length() - 1);
        reverseStr(s, 0, s.length() - 1);
        return s;
    }

private:
    void reverseStr(string &s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

int main() {
    string s = "abcdefg";

    Solution solution;
    cout << solution.reverseString(s, 2) << endl;

    return 0;
}
