//
// Created by TheUnicat on 2024-09-24.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
int min_cycle_length = INT32_MAX / 2;

int main() {
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start - 1].push_back(end - 1);
        graph[end - 1].push_back(start - 1);
    }

    for (int i = 0; i < n; i++) {
        vector<int> min_dist(n, INT32_MAX / 2);
        min_dist[i] = 0;
        queue<int> bfs;
        bfs.push(i);
        while (!bfs.empty()) {
            int curr = bfs.front();
            bfs.pop();
            for (int node : graph[curr]) {
                if (min_dist[node] >= min_dist[curr]) min_cycle_length = min(min_cycle_length, min_dist[curr] + min_dist[node] + 1);
                if (min_dist[curr] + 1 < min_dist[node]) {
                    min_dist[node] = min_dist[curr] + 1;
                    bfs.push(node);
                }
            }
        }
    }

    if (min_cycle_length == INT32_MAX / 2) {
        cout << -1;
        return 0;
    }
    cout << min_cycle_length;
}