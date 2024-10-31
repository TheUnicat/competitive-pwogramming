//
// Created by TheUnicat on 2024-10-30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using int_pair = pair<ll, ll>;

ll n, m;
ll mod_n = 1000000007;
vector<vector<pair<ll, ll>>> graph;
vector<ll> dist;
vector<bool> visited;
vector<ll> min_flights;
vector<ll> n_flights;
vector<ll> max_flights;

int main() {
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n, 1e18);
    visited.resize(n, false);
    min_flights.resize(n);
    max_flights.resize(n);
    n_flights.resize(n, 0);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].emplace_back(b - 1, c);
    }

    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> dijkstra;
    dijkstra.emplace(0, 0);
    dist[0] = 0;
    min_flights[0] = 0;
    max_flights[0] = 0;
    n_flights[0] = 1;
    while (!dijkstra.empty()) {
        int_pair top = dijkstra.top();
        dijkstra.pop();
        ll w = dist[top.second], node = top.second;
        if (visited[node]) continue;
        visited[node] = true;
        for (auto connection : graph[node]) {
            ll path_l = connection.second, next_place = connection.first;
            if (visited[next_place]) continue;
            if (path_l + w < dist[next_place]) {
                dist[next_place] = w + path_l;
                min_flights[next_place] = min_flights[node] + 1;
                max_flights[next_place] = max_flights[node] + 1;
                dijkstra.emplace(dist[next_place], next_place);
                n_flights[next_place] = n_flights[node];
            }
            else if (path_l + w == dist[next_place]) {
                min_flights[next_place] = min(min_flights[next_place], min_flights[node] + 1);
                max_flights[next_place] = max(max_flights[next_place], max_flights[node] + 1);
                n_flights[next_place] += n_flights[node];
                n_flights[next_place] %= mod_n;
            }
        }
    }

    cout << dist[n - 1] << " " << n_flights[n - 1] << " " << min_flights[n - 1] << " " << max_flights[n - 1];
}