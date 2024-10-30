//
// Created by TheUnicat on 2024-10-29.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, t;
vector<vector<int>> grass_cost;
vector<vector<vector<int>>> min_cost;
vector<vector<vector<bool>>> visited;

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    cin >> n >> t;
    grass_cost.resize(n, vector<int>(n));
    min_cost.resize(n, vector<vector<int>>(n, vector<int>(3, 1e9)));
    visited.resize(n, vector<vector<bool>>(n, vector<bool>(3, false)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> grass_cost[i][j];
    }

    priority_queue<pair<int, pair<pair<int, int>, int>>, vector<pair<int, pair<pair<int, int>, int>>>, greater<pair<int, pair<pair<int, int>, int>>>> dijkstra;
    min_cost[0][0][0] = 0;
    dijkstra.emplace(0, make_pair(make_pair(0, 0), 0));


    while (!dijkstra.empty()) {
        auto top = dijkstra.top();
        int cost = top.first, x = top.second.first.first, y = top.second.first.second, turn = top.second.second;
        dijkstra.pop();
        if (visited[x][y][turn]) continue;
        visited[x][y][turn] = true;
        for (auto movement : movements) {
            int new_x = x + movement.first, new_y = y + movement.second;
            if (!inside(new_x, new_y)) continue;
            if (visited[new_x][new_y][(turn + 1) % 3]) continue;
            int new_cost = min_cost[x][y][turn] + t;
            if ((turn + 1) % 3 == 0) new_cost += grass_cost[new_x][new_y];
            if (new_cost < min_cost[new_x][new_y][(turn + 1) % 3]) {
                min_cost[new_x][new_y][(turn + 1) % 3] = new_cost;
                dijkstra.emplace(new_cost, make_pair(make_pair(new_x, new_y), (turn + 1) % 3));
            }
        }
    }

    int min_cost_end = 2000000000;
    for (int i = 0; i < 3; i++) min_cost_end = min(min_cost_end, min_cost[n - 1][n - 1][i]);
    cout << min_cost_end;
}