//
// Created by TheUnicat on 2024-09-27.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using ll = long long;
using namespace std;

ll n, s;
ll mecho_x, mecho_y, home_x, home_y;
vector<vector<char>> grid;
vector<vector<ll>> time_for_bees;

vector<pair<ll, ll>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool inside(ll x, ll y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool is_possible(ll time) {
    vector<vector<ll>> min_time(n, vector<ll>(n, LLONG_MAX));
    vector<vector<bool>> mecho_visited(n, vector<bool>(n, false));
    queue<pair<ll, ll>> bfs;
    bfs.emplace(mecho_x, mecho_y);
    if (time * s >= time_for_bees[mecho_x][mecho_y]) bfs.pop();
    mecho_visited[mecho_x][mecho_y] = true;
    vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
    dist[mecho_x][mecho_y] = 0;
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        ll x = top.first, y = top.second;
        if (x == home_x && y == home_y) return true;
        ll curr_steps = dist[x][y];
        if (curr_steps + time * s >= time_for_bees[x][y]) continue;

        for (auto dir : directions) {
            ll new_x = x + dir.first;
            ll new_y = y + dir.second;
            if (!inside(new_x, new_y)) continue;

            ll next_time = time * s + curr_steps + 1;
            if (grid[new_x][new_y] != 'T' && !mecho_visited[new_x][new_y] && next_time < time_for_bees[new_x][new_y]) {
                dist[new_x][new_y] = curr_steps + 1;
                bfs.emplace(new_x, new_y);
                mecho_visited[new_x][new_y] = true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> s;
    grid.resize(n, vector<char>(n));
    queue<pair<ll, ll>> hives;
    time_for_bees.resize(n, vector<ll>(n, LLONG_MAX));
    vector<vector<bool>> bees_visited(n, vector<bool>(n, false));
    for (ll i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (ll j = 0; j < n; j++) {
            grid[i][j] = line[j];
            if (line[j] == 'M') {
                mecho_x = i;
                mecho_y = j;
            }
            else if (line[j] == 'D') {
                home_x = i;
                home_y = j;
            }
            else if (line[j] == 'H') {
                time_for_bees[i][j] = 0;
                hives.emplace(i, j);
                bees_visited[i][j] = true;
            }
        }
    }

    while (!hives.empty()) {
        auto top = hives.front();
        hives.pop();
        ll x = top.first, y = top.second;
        ll curr_val = time_for_bees[x][y];

        for (auto dir : directions) {
            ll new_x = x + dir.first;
            ll new_y = y + dir.second;
            if (!inside(new_x, new_y)) continue;

            if ((grid[new_x][new_y] == 'G' || grid[new_x][new_y] == 'M') && !bees_visited[new_x][new_y]) {
                time_for_bees[new_x][new_y] = curr_val + s;
                hives.emplace(new_x, new_y);
                bees_visited[new_x][new_y] = true;
            }
        }
    }
    time_for_bees[home_x][home_y] = LLONG_MAX;

    ll max_time = 1e9;
    ll min_time = 0;
    ll max_time_eating = -1;

    while (max_time >= min_time) {
        ll mid = min_time + (max_time - min_time) / 2;
        if (is_possible(mid)) {
            max_time_eating = mid;
            min_time = mid + 1;
        }
        else max_time = mid - 1;
    }

    cout << max_time_eating;
}