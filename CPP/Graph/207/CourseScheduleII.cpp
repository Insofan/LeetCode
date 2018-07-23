//
// Created by Insomnia on 2018/7/19.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphNode {
    int label;
    vector<GraphNode *> neighbors;

    GraphNode(int x) : label(x) {}

};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<GraphNode *> graph;
        vector<int> degree;

        for (int i = 0; i < numCourses; ++i) {
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }

        for (int j = 0; j < prerequisites.size(); ++j) {
            GraphNode *begin = graph[prerequisites[j].second];
            GraphNode *end = graph[prerequisites[j].first];
            begin->neighbors.push_back(end);
            degree[prerequisites[j].first]++;
        }

        queue<GraphNode *> Q;
        for (int k = 0; k < numCourses; ++k) {
            if (degree[k] == 0) {
                Q.push(graph[k]);
            }
        }

        while (!Q.empty()) {
            GraphNode *node = Q.front();
            Q.pop();
            for (int i = 0; i < node->neighbors.size(); ++i) {
                degree[node->neighbors[i]->label]--;
                if (degree[node->neighbors[i]->label] == 0) {
                    Q.push(node->neighbors[i]);
                }
            }
        }

        for (int g = 0; g < graph.size(); ++g) {
            delete graph[g];
        }

        for (int l = 0; l < degree.size(); ++l) {
           if (degree[l]) {
               return false;
           }
        }
        return true;
    }
};
int main() {
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));

    Solution sol;
    cout << boolalpha << sol.canFinish(4, prerequisites) << endl;

    return 0;
}
