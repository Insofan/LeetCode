// 
// Created by Insomnia on 18-8-12.
//

//hash solution

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateNumber(vector<int> & vec) {
        map<int, int> vecMap;

        for (int i = 0; i < vec.size(); ++i) {
            vecMap[vec[i]]++;
        }

        for (int j = 0; j < vecMap.size(); ++j) {
            if (vecMap[j] > 1) {
                return j;
            }
        }

        return  -1;
    }
};
int main () {
    int nums[7] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> vec;
    for (int i = 0; i < 7; ++i) {
       vec.push_back(nums[i]);
    }

    Solution solution;

    cout << solution.duplicateNumber(vec) << endl;

    return  0;
}
