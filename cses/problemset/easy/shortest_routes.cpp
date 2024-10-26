//
// Created by TheUnicat on 2024-10-25.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int n, m;
vector<vector<pair<int, ll>>> adj;
vector<bool> visited;
vector<ll> dist;
priority_queue<pair<ll, int>> pq;

int main() {
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    dist.resize(n, 10e17);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a - 1].emplace_back(b - 1, w);
    }

    pq.emplace(0, 0);
    dist[0] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int curr_node = top.second;
        if (visited[curr_node]) continue;
        visited[curr_node] = true;

        for (auto edge : adj[curr_node]) {
            int next_node = edge.first;
            ll w = edge.second;
            if (visited[next_node]) continue;
            if (dist[next_node] > dist[curr_node] + w) {
                dist[next_node] = dist[curr_node] + w;
                pq.emplace(-dist[next_node], next_node);
            }
        }
    }

    for (ll min_dist : dist) cout << min_dist << " ";
}