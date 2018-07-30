//
// Created by Insomnia on 2018/7/27.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int BFS_graph(string &beginWord, string &endWord, map<string, vector<string>> &graph) {
        queue<pair<string, int>> countQueue;
        set<string> visit;

        countQueue.push(make_pair(beginWord, 1));
        visit.insert(beginWord);

        while (visit.size() != graph.size()) {
            string node = countQueue.front().first;
            int step = countQueue.front().second;


        }

    }


private:


bool connect(const string &word1, const string &word2) {
    int cnt = 0;
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) {
            cnt++;
        }
    }
    return cnt == 1;
}

void constructGraph(string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph) {
    wordList.push_back(beginWord);
    for (int i = 0; i < wordList.size();
         i++) {
        graph[wordList[i]] = vector<string>();
    }

    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i + 1; j < wordList.size(); j++) {
            if (connect(wordList[i], wordList[j])) {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
}

};


int main() {

    return 0;
}
