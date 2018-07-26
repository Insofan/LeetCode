//
// Created by Insomnia on 18-7-26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//s中最小包含t的子串

class Solution {
public:
    bool isInWindow(int mapS[], int mapT[], vector<int> &strVec) {

        for (int i = 0; i < strVec.size(); ++i) {
           if (mapS[strVec[i]] < mapT[strVec[i]]) {
               return false;
           }
        }
        return true;
    }

    string minWindow(string s, string t) {
        static const int MAX_LEN = 128;
        int mapS[MAX_LEN] = {0};
        int mapT[MAX_LEN] = {0};

        /*
        for (int i = 0; i < s.size(); ++i) {
            mapS[s[i]]++;
        }

        for (int i = 0; i < t.size(); ++i) {
            mapT[s[i]]++;
        }
         */
        for (int i = 0; i < t.length(); i++){
            mapT[t[i]]++;
        }
        vector<int> strVec;
        for (int i = 0; i < MAX_LEN; i++){
            if (mapT[i] > 0){
                strVec.push_back(i);
            }
        }




        int windowBegin = 0;
        string result;

        for (int i = 0; i < s.length(); ++i) {
            mapS[s[i]]++;
            while (windowBegin < i) {
                char beginCh = s[windowBegin];
                if (mapT[beginCh] == 0) {
                    windowBegin++;
                } else if (mapS[beginCh] > mapT[beginCh]) {
                   mapS[beginCh]--;
                    windowBegin++;
                } else {
                    break;
                }
            }

            if (isInWindow(mapS, mapT, strVec)) {
                int newWindowLen = i - windowBegin + 1;
                if (newWindowLen < result.length() || result == "") {
                   result = s.substr(windowBegin, newWindowLen);
                }
            }
        }
        return result;
    }

};

int main () {
    Solution solve;
    string result = solve.minWindow("ADOBECODEBANC", "ABC");
    cout << result << endl;
    result = solve.minWindow("MADOBCCABEC", "ABCC");
    cout << result << endl;
    result = solve.minWindow("aa", "aa");
    cout << result << endl;
    return 0;
}
