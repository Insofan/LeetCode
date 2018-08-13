// 
// Created by Insomnia on 2018/8/13.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

vector<int> randomVec(int len , int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(0));
    for (int i = 0; i < len; ++i) {
        int x = rand() % maxNum;
        tempVec.push_back(x);
    }
    return tempVec;
}

void printVec(vector<int> &vec) {
    vector<int>::const_iterator it;
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        cout << (*it) <<" ";
    }
    cout << endl;
}


void insertSort(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j>= 0 && vec[j] >= key) {
           vec[j+1] = vec[j];
           j--;
        }
        vec[j + 1] = key;
    }
}
int main() {

    vector<int> vec = randomVec(10, 50);
    cout << endl;
    printVec(vec);
    insertSort(vec);
    printVec(vec);
    return 0;
}

