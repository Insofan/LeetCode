// 
// Created by Insomnia on 18-10-8.
//同 leetcode

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //主要两个函数to_string, stoi
    int minNumOffer(vector<int> vec) {
        string res;
        sort(vec.begin(), vec.end(), [](int x, int y) {
            return (to_string(x) + to_string(y)) < (to_string(y) + to_string(x));
        });
        for (int i = 0; i < vec.size(); ++i) {
           res += to_string(vec[i]);
        }

        return res[0] == '0' ? 0 : stoi(res);
    }


    string minNumOffer2(vector<int> nums) {
        string res;

        sort(nums.begin(), nums.end(), [](int x, int y) {
            return (to_string(x) + to_string(y)) < (to_string(y) + to_string(x));
        });

        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }

        int count = 0;
        for (int i = 0; i < res.length(); i++) {
            if (res[i] == '0') {
                count++;
            } else {
                break;
            }
        }

        string tmp = res.substr(count, res.length() - count);
        return tmp.length() == 0 ? "0" : tmp;
    }
};

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }
    return tempVec;
}

int main() {
    int arr[] = {32, 3, 321};
    vector<int> vec(&arr[0], &arr[3]);
    Solution solution;
    cout << solution.minNumOffer(vec) << endl;
    cout << solution.minNumOffer2(vec) << endl;


    return 0;
}
