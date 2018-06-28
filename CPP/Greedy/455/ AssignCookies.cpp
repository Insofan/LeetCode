//
// Created by Insomnia on 2018/6/28.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {
                child++;
            }
            cookie++;
        }
        return child;
    }

};

int main() {
    vector<int> child;
    vector<int> cookies;
    child.push_back(1);
    child.push_back(2);
    child.push_back(3);


    cookies.push_back(1);
    cookies.push_back(1);

    Solution sol;
    std::cout << sol.findContentChildren(child, cookies) << endl;


    return 0;
}
