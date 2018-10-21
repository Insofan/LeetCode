// 
// @ClassName ReverseStringI
// @Description Leetcode 344
// @Date 18-10-21 下午10:15
// @Created by Insomnia
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            //swap(s[l++], s[r--]);
            swapStr(s[l++], s[r--]);
        }
        return s;
    }

private:
    void swapStr(char &x, char &y) {
        char tmp = x;
        x = y;
        y = tmp;
    }
};

int main() {
    string s = "I am a student.";
    Solution solution;

    cout << solution.reverseStr(s) << endl;

    return 0;
}
