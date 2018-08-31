//
// Created by Insomnia on 2018/8/31.
// MIT License
//
#include <iostream>
#include <vector>

using namespace std;


void out(vector<int> &vec) {

    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }
    return tempVec;
}


class Solution {
public:
    void heapSort(vector<int> &vec) {
        int len = vec.size();

        for (int i = (len - 2) / 2; i >= 0; i--) {
            filterDown(vec, i, len - 1);
        }

        for (int i = len - 1; i > 0; i--) {
            swap(vec, 0, i);
            filterDown(vec, 0, i - 1);
        }

    }

private:
    void filterDown(vector<int> &vec, int current, int last) {

    }
};

int main() {
    vector<int> vec = randomVec(10, 50);
    out(vec);


    out(vec);

    return 0;
}