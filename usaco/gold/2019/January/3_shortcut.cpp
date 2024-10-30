//
// Created by TheUnicat on 2024-10-29.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, m, t;
vector<vector<pair<int, int>>> graph;
vector<int> cows;
vector<int> n_cow_visits;
vector<int> dist;
vector<bool> visited;
vector<int> prev_node;

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin >> n >> m >> t;
    graph.resize(n);
    cows.resize(n);
    n_cow_visits.resize(n, 0);
    visited.resize(n, false);
    dist.resize(n, 1e9);
    prev_node.resize(n);
    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].emplace_back(b - 1, w);
        graph[b - 1].emplace_back(a - 1, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
    dijkstra.emplace(0, 0);
    dist[0] = 0;
    while (!dijkstra.empty()) {
        auto top = dijkstra.top();
        dijkstra.pop();
        int w = top.first, node = top.second;
        if (visited[node]) continue;
        visited[node] = true;

        for (auto connection : graph[node]) {
            int next_node = connection.first, path_w = connection.second;
            if (visited[next_node]) continue;
            int new_cost = w + path_w;
            if (new_cost < dist[next_node]) {
                dist[next_node] = new_cost;
                dijkstra.emplace(new_cost, next_node);
                prev_node[next_node] = node;
            }
            else if (new_cost == dist[next_node]) prev_node[next_node] = min(prev_node[next_node], node);
        }
    }

    for (int i = 1; i < n; i++) {
        int curr_node = i;
        int cows_here = cows[i];
        while (curr_node != 0) {
            n_cow_visits[curr_node] += cows_here;
            curr_node = prev_node[curr_node];
        }
    }

    ll max_saved = 0;
    for (int i = 1; i < n; i++) max_saved = max(max_saved, n_cow_visits[i] * (ll) (dist[i] - t));
    cout << max_saved;
}