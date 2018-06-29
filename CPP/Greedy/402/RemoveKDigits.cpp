//
// Created by Insomnia on 2018/6/28.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;
        string result = "";

        for (int i = 0; i < num.length(); ++i) {
           int number = num[i] - '0';
           while (S.size() != 0 && /**/ k >0) {
               S.pop_back();
               /* */
           }
           if () {

           }
        }

    }
};


int main() {



    return 0;
}
