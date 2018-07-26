// 
// Created by Insomnia on 18-7-26.
//

#include <vector>
#include <iostream>

using namespace std;

bool isWindowOk(int mapS[], int mapT[], vector<int> &vecT) {
    for (int i = 0; i < vecT.size(); ++i) {
        if (mapS[vecT[i]] < mapT[vecT[i]]) {
            return false;//如果s出现小于t中出现该字符的数量 返回假
        }
    }
    return true;
}

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABCDAB";

    static const int MAX_ARRAY_LEN = 128;
    int mapS[MAX_ARRAY_LEN] = {0};
    int mapT[MAX_ARRAY_LEN] = {0};

    for (int i = 0; i < s.length(); ++i) {
        mapS[s[i]]++;
    }

    for (int i = 0; i < t.length(); ++i) {
        mapT[s[i]]++;
    }

    vector<int> vecT;
    for (int j = 0; j < MAX_ARRAY_LEN; ++j) {
        if (mapT[j] > 0) {
            vecT.push_back(j);
        }
    }

    cout << boolalpha << isWindowOk(mapS, mapT, vecT) << endl;
    return 0;
}