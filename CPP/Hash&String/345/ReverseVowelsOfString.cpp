//
// @ClassName ReverseVowelsOfString
// @Description TODO
// @Date 2019/1/24 4:53 PM
// @Created by Insomnia
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> chVec;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o') {
                chVec.push_back(i);
            }
        }

        int i = 0;
        int j = chVec.size() - 1;
        while (i < j) {
            swap(s[chVec[i++]], s[chVec[j--]]);
        }
        return s;
    }
};

/*!
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
 */


int main() {
    string s = "hello";
    Solution sol;
    cout << sol.reverseVowels(s) << endl;

    return 0;
}
