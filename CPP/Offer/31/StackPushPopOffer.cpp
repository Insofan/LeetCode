//
// Created by Insomnia on 2018/9/6.
//

#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool pushAndPopOrder(vector<int> inVec, vector<int> outVec) {
        stack<int> s;
        int index = 0;
        for (int i = 0; i < inVec.size(); i++) {
            s.push(inVec[i]);
            //cout << s.top() << ": " << s.size() << endl;

            while (!s.empty() && s.top() == outVec[index]) {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }

};


int main() {
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {4, 5, 3, 2, 1};
    int a3[] = {4, 3, 5, 1, 2};
    vector<int> vec1(&a1[0], &a1[5]);
    vector<int> vec2(&a2[0], &a2[5]);
    vector<int> vec3(&a3[0], &a3[5]);

    Solution solution;
    cout <<  boolalpha <<solution.pushAndPopOrder(vec1, vec2) << endl;
    cout <<  boolalpha <<solution.pushAndPopOrder(vec1, vec3) << endl;



    return 0;
}
