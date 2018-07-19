//
// Created by Insomnia on 2018/7/19.
//

#include <iostream>
#include <vector>
using namespace std;

struct GraphNode {
    int label;
    vector<GraphNode *> neighbors;

    GraphNode(int x) : label(x) {}

};



class Solution {
public:
    //其中的 pair, second 依赖first
    //-1 没有访问过, 0 正在访问, 1 已经访问完成
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<GraphNode *> graph;
        vector<int> visit;

        for (int i = 0; i < numCourses; ++i) {
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }

        for (int j = 0; j < prerequisites.size(); ++j) {
            GraphNode *begin = graph[prerequisites[j].second];
            GraphNode *end = graph[prerequisites[j].first];
            begin->neighbors.push_back(end);
        }

        for (int k = 0; k < graph.size(); ++k) {
            if (visit[k] == -1 && !DFS_graph(graph[k], visit)) {
                return false;
            }
        }

        for (int l = 0; l < numCourses; ++l) {
            delete graph[l];
        }

        return true;
    }

private:
    bool DFS_graph(GraphNode *node, vector<int> &visit)  {
        visit[node->label] = 0;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (visit[node->neighbors[i]->label] == -1) {
                if (DFS_graph(node->neighbors[i], visit)  == 0) {
                    return false;
                }
            } else if (visit[node->neighbors[i]->label] == 0) {
                return false;
            }
        }
        visit[node->label] = 1;
        return true;
    }
};

int main() {
    return 0;
}
