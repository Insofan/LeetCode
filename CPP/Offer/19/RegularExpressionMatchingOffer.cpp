//
// @ClassName RegularExpressionMatchingOffer
// @Description Leetcode 10 Regular Expression Matching
// @Date 2018/10/24 上午9:47
// @Created by Insomnia
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        //因此是从1开始的所以要加1, m - 1, j - 1是当前值
        vector<vector<bool>> res(m + 1, vector<bool>(n + 1, false));

        //0 0 是true
        res[0][0] = true;
        //s有值, p无值, 为false
        for (int i = 1; i <= m; i++) {
            res[i][0] = false;
        }

        //完成dp的base
        for (int j = 1; j <= n; j++) {
            res[0][j] = j > 1 && p[j - 1] == '*' && res[0][j - 2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    res[i][j] = res[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    res[i][j] = res[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && res[i - 1][j];
                }
            }
        }
        return res[m][n];
    }

private:
};

int main() {
    string s1 = "aa";
    string p1 = "a";

    string s2 = "aa";
    string p2 = "a*";

    string s3 = "ab";
    string p3 = ".*";

    Solution solution;
    cout << s1 << " " << p1 << " " << boolalpha << solution.isMatch(s1, p1) << endl;
    cout << s2 << " " << p2 << " " << boolalpha << solution.isMatch(s2, p2) << endl;
    cout << s3 << " " << p3 << " " << boolalpha << solution.isMatch(s3, p3) << endl;

    return 0;
}
