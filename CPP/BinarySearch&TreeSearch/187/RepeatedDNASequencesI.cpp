//
// Created by Insomnia on 2018/7/26.
//

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> wordMap;
        vector<string> result;

        for (int i = 0; i < s.length(); ++i) {
            string word = s.substr(i, 10);
            if (wordMap.find(word) != wordMap.end()) {
                wordMap[word]++;
            } else {
                wordMap[word] = 1;
            }
        }

        map<string, int>::iterator it;
        for (it = wordMap.begin(); it != wordMap.end(); it++) {
           if (it->second > 1 ) {
              result.push_back(it->first);
           }
        }
        return result;
    }
};

int main() {

    return 0;
}
