//
// Created by Insomnia on 2018/7/1.
//

//http://poj.org/problem?id=2431
//最优加油方法, 用贪心和数据结构结合 hard
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

//pair 是每个加油站到终点的距离
int getMininumStop(int L, int P, vector<pair<int, int>> &stop) {
    priority_queue<int> Q;
    int result = 0;
    stop.push_back(make_pair(0, 0));

    sort(stop.begin(), stop.end(), cmp);

    for (int i = 0; i < stop.size(); ++i) {
        int dis = L - stop[i].first;
        while (!Q.empty() && P > dis) {
            P += Q.top();
            Q.pop();
            result++;
        }

        if (Q.empty() && P < dis) {
            return -1;
        }
        P = P - dis;
        L = stop[i].first;
        Q.push(stop[i].second);
    }
}

int main() {
    vector<pair<int, int>> stop;
    int N;
    int L;
    int P;

    int distance;
    int fuel;
    cout << "hhe" << endl;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
       scanf("%d %d", &distance, &fuel);
       stop.push_back(make_pair(distance, fuel));
    }

    scanf("%d %d", &L, &P);
    printf("%d\n", getMininumStop(L, P, stop));
    return 0;
}
