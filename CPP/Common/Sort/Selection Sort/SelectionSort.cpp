// 
// Created by Insomnia on 2018/8/13.
//

#include <iostream>
#include <time.h>
#include <random>
#include <vector>

using namespace std;

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));

    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }

    return tempVec;
}

void printVec(vector<int> &vec){

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
class Solution {

public:
    void selectionSort(vector<int> &vec) {
        for (int i = 0; i < vec.size(); ++i) {
            int index = i;
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] <= vec[index]) {
                    index = j;
                }
            }

            if (index != i) {
                swap(vec[i], vec[index]);
            }
        }
    }
};
int main () {
    vector<int> vec = randomVec(10, 60);
    printVec(vec);
    Solution solution;
   solution.selectionSort(vec);
    printVec(vec);

    return  0;
}