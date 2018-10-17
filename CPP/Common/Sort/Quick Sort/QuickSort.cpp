//
// Created by Insomnia on 2018/8/14.
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
    void quickSort(vector<int> &vec, int left, int right) {
        if (left < right) {
            int pivot = partition(vec, left, right);
            quickSort(vec, left, pivot - 1);
            quickSort(vec, pivot + 1, right);
        }

    }

private:
    int partition(vector<int> &vec, int left, int right) {
        int pivot = vec[right];
        int j = left - 1;
        for (int i = left; i <= right; ++i) {
            if (vec[i] < pivot) {
                j++;
                swap(vec[j], vec[i]);
            }

        }

        swap(vec[j + 1], vec[right]);

        return j + 1;
    }
};

class Solution2 {
public:
    void quickSortWhile(vector<int> &vec, int left, int right) {
        int i = left;
        int j = right;
        int pivot = vec[left];

        while (i < j) {
            while (i < j && vec[j] >= pivot) {
                j--;
            }
            if (i < j) {
                swap(vec[i], vec[j]);
            }

            while (i < j && vec[i] <= pivot) {
                i++;
            }

            if (i < j) {
                swap(vec[i], vec[j]);
            }
        }

        if (i != left) {
            quickSortWhile(vec, left, i - 1);
        }
        if (j != right) {
            quickSortWhile(vec, j+1, right);
        }
    }
};

int main() {
//    vector<int> vec = randomVec(10, 60);
//    out(vec);
//    Solution solution;
//    solution.quickSort(vec, 0, vec.size() - 1);
//    out(vec);
    
    vector<int> vec = randomVec(10, 60);
    out(vec);
    Solution2 solution2;
    solution2.quickSortWhile(vec, 0, vec.size() - 1);
    out(vec);

    return 0;
}