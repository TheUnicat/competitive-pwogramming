//
// Created by TheUnicat on 2024-09-26.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
using namespace std;

int x, y, k, m;
vector<vector<int>> dist(201, vector<int>(201, INT32_MAX));

int main() {
    dist[0][0] = 0;
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;
    int min_diff = 202;

    queue<pair<int, int>> bfs;
    bfs.emplace(0, 0);

    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        int curr_x = top.first, curr_y = top.second;

        int curr_cost = dist[curr_x][curr_y];
        if (curr_cost == k) continue;
        int new_cost = curr_cost + 1;

        if (dist[x][curr_y] > new_cost) {
            dist[x][curr_y] = new_cost;
            bfs.emplace(x, curr_y);
        }

        if (dist[curr_x][y] > new_cost) {
            dist[curr_x][y] = new_cost;
            bfs.emplace(curr_x, y);
        }

        int y_into_x_x = min(x, curr_x + curr_y);
        int y_into_x_y = curr_y - (y_into_x_x - curr_x);

        if (dist[y_into_x_x][y_into_x_y] > new_cost) {
            dist[y_into_x_x][y_into_x_y] = new_cost;
            bfs.emplace(y_into_x_x, y_into_x_y);
        }

        int x_into_y_y = min(y, curr_x + curr_y);
        int x_into_y_x = curr_x - (x_into_y_y - curr_y);

        if (dist[x_into_y_x][x_into_y_y] > new_cost) {
            dist[x_into_y_x][x_into_y_y] = new_cost;
            bfs.emplace(x_into_y_x, x_into_y_y);
        }

        if (dist[curr_x][0] > new_cost) {
            dist[curr_x][0] = new_cost;
            bfs.emplace(curr_x, 0);
        }

        if (dist[0][curr_y] > new_cost) {
            dist[0][curr_y] = new_cost;
            bfs.emplace(0, curr_y);
        }
    }

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (dist[i][j] <= k) min_diff = min(min_diff, abs(m - (i + j)));
        }
    }

    cout << min_diff;
}