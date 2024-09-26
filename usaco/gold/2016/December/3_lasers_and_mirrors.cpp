//
// Created by TheUnicat on 2024-09-25.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <cstdint>
using namespace std;

int n, x_l, y_l, x_b, y_b;
vector<pair<int, int>> points;
vector<int> min_dist;
map<int, vector<int>> horizontal;
map<int, vector<int>> vertical;

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    cin >> n >> x_l >> y_l >> x_b >> y_b;
    horizontal[x_l].push_back(0);
    vertical[y_l].push_back(0);
    horizontal[x_b].push_back(1);
    vertical[y_b].push_back(1);
    min_dist.push_back(-1);
    points.emplace_back(x_l, y_l);
    min_dist.push_back(INT32_MAX);
    points.emplace_back(x_b, y_b);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        horizontal[x].push_back(i + 2);
        vertical[y].push_back(i + 2);
        min_dist.push_back(INT32_MAX);
        points.emplace_back(x, y);
    }

    queue<pair<int, bool>> bfs;
    bfs.emplace(0, false);
    bfs.emplace(0, true);
    while (!bfs.empty()) {
        auto top = bfs.front();
        int x = points[top.first].first, y = points[top.first].second;
        bool dir = top.second;
        bfs.pop();

        int curr_cost = min_dist[top.first];

        if (dir == true) {
            for (int node : horizontal[x]) {
                if (min_dist[node] > 1 + curr_cost) {
                    min_dist[node] = 1 + curr_cost;
                    bfs.emplace(node, false);
                }
            }
        }
        else for (int node : vertical[y]) {
            if (min_dist[node] > 1 + curr_cost) {
                min_dist[node] = 1 + curr_cost;
                bfs.emplace(node, true);
            }
        }
    }

    if (min_dist[1] == INT32_MAX) {
        cout << -1;
        return 0;
    }
    cout << min_dist[1];
}