//
// Created by Insomnia on 2018/8/30.
//

#include <stdio.h>
#include <iostream>


using namespace std;

class Solution {
public:
    int solution(int &num) {
        int res = 0;
        while (num) {
            res++;
            num &= num - 1;
        }
        return res;
    }
};

int main() {

    Solution solution;

    int num = 2;
    cout << num << " one count : " << solution.solution(num) << endl;
    num = 8;
    cout << num << " one count : " << solution.solution(num) << endl;
    num = 5;
    cout << num << " one count : " << solution.solution(num) << endl;
    num = 7;
    cout << num << " one count : " << solution.solution(num) << endl;


    return 0;
}
