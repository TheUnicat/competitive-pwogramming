//
// Created by TheUnicat on 2024-10-13.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int n, m, c;
vector<int> min_time;
vector<int> sorted;
vector<vector<pair<int, int>>> edges;
vector<int> indegree;

int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    cin >> n >> m >> c;
    edges.resize(n);
    indegree.resize(n, 0);
    min_time.resize(n);
    for (int i = 0; i < n; i++) cin >> min_time[i];
    for (int i = 0; i < c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        indegree[b - 1]++;
        edges[a - 1].emplace_back(b - 1, x);
    }

    queue<int> kahn;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) kahn.push(i);

    while (!kahn.empty()) {
        int top = kahn.front();
        kahn.pop();
        sorted.push_back(top);
        for (auto edge : edges[top]) {
            indegree[edge.first]--;
            min_time[edge.first] = max(min_time[edge.first], min_time[top] + edge.second);
            if (indegree[edge.first] == 0) kahn.push(edge.first);
        }
    }

    for (int time : min_time) cout << time << endl;
}