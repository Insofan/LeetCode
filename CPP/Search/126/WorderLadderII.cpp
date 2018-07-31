//
// Created by Insomnia on 2018/7/31.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Qitem {
    string word;
    int node;
    int step;

    Qitem(string wor, int index, int ste) : word(wor), node(index), step(ste) {}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        map<string, vector<string>> graph;

        constructGraph(beginWord, wordList, graph);

        vector<Qitem> Q;
        vector<int> endWordPos;

        BFS_search(beginWord, endWord, graph, Q, endWordPos);

        vector<vector<string>> result;

        for (int i = 0; i < endWordPos.size(); ++i) {
            int pos = endWordPos[i];

            vector<string> path;

            while  (pos  != -1) {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }

            result.push_back(vector<string>());

            for (int j = path.size() - 1; j >=0 ; j--) {
               result[i].push_back(path[j]);
            }
        }

    }

private:
    bool connect(string word1, string word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); ++i) {
            for (int j = 0; j < word2.length(); ++j) {
                if (word1[i] != word2[j]) {
                    count++;
                }
            }
        }
        return count == 1;
    }

    void BFS_search(string &beginWord, string &endWord, map<string, vector<string>> &graph, vector<Qitem> &Q,
                    vector<int> &endWordPos) {
        map<string, int> visit;
        int minStep = 0;
        Q.push_back(Qitem(beginWord, -1, 1));

        visit[beginWord] = 1;
        int front = 0;

        while (front != Q.size()) {
            string &node = Q[front].node;
            int step = Q[front].step;

            if (minStep != 0 && step > minStep) {
                break;
            }

            if (node == endWord) {
                minStep = step;
                endWordPos.push_back(front);
            }

            const vector<string> &neighbors = graph[node];

            for (int i = 0; i < neighbors.size(); ++i) {
                if ((visit.find(neighbors[i]) == visit.end()) || (visit[neighbors[i]] == step + 1)) {
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
    }

    void constructGraph(string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph) {
        int hasBeginWord = 0;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) {
                hasBeginWord = 1;
            }
            graph[wordList[i]] = vector<string>();
        }

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (connect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }

            if (hasBeginWord == 0 && connect(beginWord, wordList[i])) {
                graph[beginWord].push_back([wordList[i]]);
            }
        }
    }

};

int main() {

    return 0;
}
