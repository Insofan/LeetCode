//
// Created by Insomnia on 2018/6/30.
//

//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
//射气球

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        if (points.size() == 0) {
            return 0;
        }

        sort(points.begin(), points.end(), cmp);
        int shootNum = 1;
        int shootBegin = points[0].first;
        int shootEnd = points[0].second;

        for (int i = 0; i < points.size(); ++i) {
            if (points[i].first <= shootEnd) {
                shootBegin = points[i].first;
                if (shootEnd > points[i].second) {
                    shootEnd = points[i].second;
                }
            } else {
                shootNum++;
                shootBegin = points[i].first;
                shootEnd = points[i].second;
            }
        }
        return shootNum;
    }
};


int main() {
    vector<pair<int, int>> points;
    points.push_back(make_pair(10, 16));
    points.push_back(make_pair(2, 8));
    points.push_back(make_pair(1, 6));
    points.push_back(make_pair(7, 12));

    Solution sol;
    cout << sol.findMinArrowShots(points) << endl;
    return 0;
}