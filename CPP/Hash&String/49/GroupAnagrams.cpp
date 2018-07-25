//
// Created by Insomnia on 2018/7/25.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string, vector< string>> anagram;
       vector<vector<string>> result;

        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());

            if (anagram.find(str) == anagram.end()) {
                vector<string> item;
                anagram[str] = item;
            }
            anagram[str].push_back(strs[i]);
        }

        for (map<string,vector<string>>::iterator it = anagram.begin(); it != anagram.end(); it++) {
           result.push_back((*it).second);
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j]  << " ";

        }
        cout << endl;
    }

    return 0;
}
