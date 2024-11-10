//
// Created by TheUnicat on 2024-11-09.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<int> dist, dist2;
vector<vector<pair<int, int>>> graph;
vector<int> haybales;
vector<bool> visited;

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin >> n >> m >> k;
    dist.resize(n, 1e9);
    dist2.resize(n, 1e9);
    graph.resize(n + 1);
    haybales.resize(n, 0);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a - 1].emplace_back(b - 1, t);
        graph[b - 1].emplace_back(a - 1, t);
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        haybales[x - 1] = max(haybales[x - 1], y);
    }

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, n - 1);
    dist[n - 1] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto edge : graph[node]) {
            int new_cost = edge.second;
            int new_node = edge.first;
            if (new_node == n - 1) continue;
            new_cost += -cost;
            if (new_cost < dist[new_node]) {
                dist[new_node] = new_cost;
                pq.emplace(-new_cost, new_node);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (haybales[i] > 0) {
            graph[n].emplace_back(i, dist[i] - haybales[i]);
        }
    }
    visited.clear();
    visited.resize(n, false);

    priority_queue<pair<int, int>> pq2;
    pq2.emplace(0, n);
    dist2[n] = 0;
    while (!pq2.empty()) {
        int cost = pq2.top().first;
        int node = pq2.top().second;
        pq2.pop();

        if (visited[node]) continue;
        visited[node] = true;
        for (auto edge : graph[node]) {
            int new_cost = edge.second;
            int new_node = edge.first;
            if (visited[new_node]) continue;
            new_cost += -cost;
            if (new_cost < dist2[new_node]) {
                dist2[new_node] = new_cost;
                pq2.emplace(-new_cost, new_node);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (dist2[i] <= dist[i]) cout << "1";
        else cout << "0";
        cout << endl;
    }
}