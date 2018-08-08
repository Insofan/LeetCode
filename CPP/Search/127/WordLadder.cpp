//
// Created by Insomnia on 2018/7/27.
//


#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string> &wordList) {
        map<string, vector<string>> graph;
        constructGraph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }

    int BFS_graph(string &beginWord, string &endWord, map<string, vector<string>> &graph) {
        queue<pair<string, int>> countQueue;
        set<string> visit;

        countQueue.push(make_pair(beginWord, 1));
        visit.insert(beginWord);

        while (!countQueue.empty()) {
            string node = countQueue.front().first;
            int step = countQueue.front().second;

            countQueue.pop();

            if (node == endWord) {
                return step;
            }

            const vector<string> &neighbors = graph[node];

            for (int i = 0; i < neighbors.size(); i++) {
                if (visit.find(neighbors[i]) == visit.end()) {
                    countQueue.push(make_pair(neighbors[i], step + 1));
                    visit.insert(neighbors[i]);
                }
            }


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

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList;

    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");

    Solution solve;
    int result = solve.ladderLength(beginWord, endWord, wordList);

    cout << "result " << result << endl;

    return 0;
}
