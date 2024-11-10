//
// Created by TheUnicat on 2024-10-31.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int n, m, s, t, u, v;
vector<vector<pair<ll, ll>>> graph(100001);
ll dist_u[100001], dist_v[100001], dist_s[100001], dp[2][100001], ans;
bool visited[100001];

void dijkstra(int start, ll dist[]) {
    fill(visited, visited + 100001, false);
    priority_queue<pair<ll, ll>> dijkstra;
    dijkstra.emplace(0, start);
    while (!dijkstra.empty()) {
        auto top = dijkstra.top();
        dijkstra.pop();
        ll node = top.second;
        ll weight = top.first;
        if (visited[node]) continue;
        visited[node] = true;
        dist[node] = -weight;

        for (auto &connection : graph[node]) {
            dijkstra.push({ weight - connection.second, connection.first});
        }
    }
}

void dijkstra_2(int start, int end) {
    fill(visited, visited + 100001, false);
    fill(dp[0], dp[0] + 100001, 1e18);
    fill(dp[1], dp[1] + 100001, 1e18);
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> dijkstra;
    dijkstra.emplace(0, make_pair(start, 0));

    while (!dijkstra.empty()) {
        auto top = dijkstra.top();
        dijkstra.pop();
        ll cost = top.first;
        int node = top.second.first;
        int parent = top.second.second;

        if (!visited[node]) {
            visited[node] = true;
            dist_s[node] = cost;
            dp[0][node] = min(dist_u[node], dp[0][parent]);
            dp[1][node] = min(dist_v[node], dp[1][parent]);
            for (auto connection : graph[node]) {
                dijkstra.emplace(cost + connection.second, make_pair(connection.first, node));
            }
        } else if (dist_s[node] == cost) {
            if (min(dist_u[node], dp[0][parent]) + min(dist_v[node], dp[1][parent]) <= dp[0][node] + dp[1][node]) {
                dp[0][node] = min(dist_u[node], dp[0][parent]);
                dp[1][node] = min(dist_v[node], dp[1][parent]);
            }
        }
    }

    ans = min(ans, dp[0][end] + dp[1][end]);
}


int main() {
    cin >> n >> m >> s >> t >> u >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    dijkstra(u, dist_u);
    dijkstra(v, dist_v);
    ans = dist_u[v];
    dijkstra_2(s, t);
    dijkstra_2(t, s);
    cout << ans;
}