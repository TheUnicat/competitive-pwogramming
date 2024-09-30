//
// Created by TheUnicat on 2024-09-28.
//

#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
using ll = long long;

int n, m;

int sq_value(int i, int j) {
    return (n * i) + j;
}

pair<int, int> sq_val_to_pair(int sq_val) {
    return make_pair(sq_val / n, sq_val % n);
}

int main() {
    cin >> n >> m;
    vector<vector<pair<int, char>>> graph(n);
    vector<vector<int>> sq_graph(n * n);
    for (int i = 0; i < m; i++) {
        int start, end;
        char c;
        cin >> start >> end >> c;
        graph[end - 1].emplace_back(start - 1, c);
        graph[start - 1].emplace_back(end - 1, c);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto c : graph[i]) {
                char val = c.second;
                int end = c.first;
                for (auto d : graph[j]) {
                    if (d.second == val) {
                        sq_graph[sq_value(i, j)].push_back(sq_value(end, d.first));
                    }
                }
            }
        }
    }

    queue<int> bfs;
    vector<ll> min_dist(n * n, LLONG_MAX / 4);
    min_dist[sq_value(0, n - 1)] = 0;

    ll min_sol = LLONG_MAX / 4;
    bfs.push(sq_value(0, n - 1));
    while (!bfs.empty()) {
        int top = bfs.front();
        bfs.pop();
        auto [i, j] = sq_val_to_pair(top);

        if (i == j) min_sol = min(min_sol, min_dist[top] * 2);

        for (auto connection : graph[i]) {
            if (connection.first == j) {
                min_sol = min(min_sol, min_dist[top] * 2 + 1);
                break;
            }
        }

        for (int connection : sq_graph[top]) {
            if (min_dist[connection] > min_dist[top] + 1) {
                min_dist[connection] = min_dist[top] + 1;
                bfs.push(connection);
            }
        }

    }

    if (min_sol == LLONG_MAX / 4) cout << -1;
    else cout << min_sol;
}