//
// Created by TheUnicat on 2024-10-28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int n = 1000, m;
vector<vector<pair<int, pair<int, int>>>> graph;

int min_cost(int flow_rate) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
    vector<bool> visited(n, false);
    vector<int> dist(1000, 1000000000);
    dist[0] = 0;
    dijkstra.emplace(0, 0);
    while (!dijkstra.empty()) {
        auto top = dijkstra.top();
        dijkstra.pop();
        int node = top.second;
        int curr_dist = dist[node];
        if (visited[node]) continue;
        visited[node] = true;

        for (auto neighbor : graph[node]) {
            if (visited[neighbor.first]) continue;
            if (neighbor.second.second < flow_rate) continue;
            if (curr_dist + neighbor.second.first < dist[neighbor.first]) {
                dist[neighbor.first] = curr_dist + neighbor.second.first;
                dijkstra.emplace(dist[neighbor.first], neighbor.first);
            }
        }
    }

    return dist[n - 1];
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, w, f;
        cin >> a >> b >> w >> f;
        graph[a - 1].emplace_back(b - 1, make_pair(w, f));
        graph[b - 1].emplace_back(a - 1, make_pair(w, f));
    }

    double min_pipes = -1;
    for (int i = 1; i <= 1000; i++) {
        min_pipes = max(min_pipes, ((double) i) / ((double) min_cost(i)));
    }

    cout << (int) (min_pipes * 1000000);
}