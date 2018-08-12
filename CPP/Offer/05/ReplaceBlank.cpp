// 
// Created by Insomnia on 18-8-12.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceBlank(string str) {
        string resStr;

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
               resStr += "%20";
            } else {
                resStr.push_back(str[i]);
            }
        }

        return resStr;
    }
};
int main(){
    string str = "Replace string wtf!";
    Solution solution;
    cout <<  solution.replaceBlank(str) << endl;


    return  0;
}
