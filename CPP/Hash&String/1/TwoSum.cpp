// 
// Created by Insomnia on 18-9-28.
//
//为了blog临时写的

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> vec, int sum) {
        vector<int> res;
        map<int, int> hashTable;

        for (int j = 0; j < vec.size(); ++j) {
           hashTable[vec[j]] = j;
        }

        for (int i = 0; i < vec.size(); ++i) {
            int target = sum  - vec[i];
            if (hashTable.find(target) != hashTable.end()) {
                if (hashTable[target] != i) {
                    res.push_back(i);
                    res.push_back(hashTable[target]);
                    return res;
                }
            }
        }
        return res;
    }
};


int main () {
    vector<int> vec = {2, 7, 11, 15};

    Solution solution;
    vector<int> res = solution.twoSum(vec, 9);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}