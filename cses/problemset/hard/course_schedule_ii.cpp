//
// Created by TheUnicat on 2024-10-21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> outdegree;
vector<int> sorted;

int main() {
    cin >> n >> m;
    graph.resize(n);
    outdegree.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b - 1].push_back(a - 1);
        outdegree[a - 1]++;
    }

    priority_queue<int> toposort;
    for (int i = 0; i < n; i++) if (outdegree[i] == 0) toposort.push(i);
    while (!toposort.empty()) {
        int top = toposort.top();
        toposort.pop();
        sorted.push_back(top);
        for (int parent : graph[top]) {
            outdegree[parent]--;
            if (outdegree[parent] == 0) toposort.push(parent);
        }
    }

    reverse(sorted.begin(), sorted.end());
    for (int node : sorted) cout << node + 1 << " ";
}