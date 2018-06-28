//
// Created by Insomnia on 2018/6/28.
//

#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
    bool canjump(vector<int> &nums) {
        vector<int> index;
        for (int i = 0; i < nums.size(); ++i) {
            index.push_back(i + nums[i]);
        }

        int jump = 0;
        int max_index = index[0];

        while (jump < index.size() && jump < max_index) {
            if (max_index < index[jump]) {
                max_index = index[jump];
            }
            jump++;
        }

        if (jump == index.size()) {
            return true;
        }
        return false;
    }
};

int main(0) {


    return 0;
}