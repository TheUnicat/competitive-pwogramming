//
// Created by TheUnicat on 2024-09-21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;
using ll = long long;
using pq_thing = pair<ll, pair<ll, bool>>;

ll t;

int main() {
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll min_time = LLONG_MAX;
        ll n, m, h;
        cin >> n >> m >> h;
        vector<bool> horse(n, false);
        vector<vector<pair<ll, ll>>> graph(n);

        for (int j = 0; j < h; j++) {
            ll node;
            cin >> node;
            horse[node - 1] = true;
        }

        for (int j = 0; j < m; j++) {
            ll start, end, w;
            cin >> start >> end >> w;
            start--;
            end--;
            graph[start].emplace_back(end, w);
            graph[end].emplace_back(start, w);
        }

        vector<vector<ll>> robin_min(n, vector<ll>(2, LLONG_MAX / 2));
        vector<vector<ll>> marian_min(n, vector<ll>(2, LLONG_MAX / 2));
        marian_min[0][0] = 0;
        robin_min[n - 1][0] = 0;

        set<pair<ll, pair<ll, bool>>> robin_bfs;
        robin_bfs.insert(make_pair(0, make_pair(n - 1, false)));
        while (!robin_bfs.empty()) {
            auto top = *robin_bfs.begin();
            ll node = top.second.first;
            bool has_horse = top.second.second;
            if (horse[node]) has_horse = true;
            robin_bfs.erase(robin_bfs.begin());

            for (auto connection : graph[node]) {
                ll new_cost = top.first;
                if (has_horse == true) new_cost += connection.second / 2;
                else new_cost += connection.second;
                ll prev_cost;
                prev_cost = robin_min[connection.first][has_horse];
                if (new_cost < prev_cost) {
                    robin_bfs.erase(make_pair(prev_cost, make_pair(connection.first, has_horse)));
                    robin_bfs.insert(make_pair(new_cost, make_pair(connection.first, has_horse)));
                    robin_min[connection.first][has_horse] = new_cost;
                }
            }
        }

        set<pair<ll, pair<ll, bool>>> marian_bfs;
        marian_bfs.insert(make_pair(0, make_pair(0, false)));
        while (!marian_bfs.empty()) {
            auto top = *marian_bfs.begin();
            ll node = top.second.first;
            bool has_horse = top.second.second;
            if (horse[node]) has_horse = true;
            marian_bfs.erase(marian_bfs.begin());

            for (auto connection : graph[node]) {
                ll new_cost = top.first;
                if (has_horse == true) new_cost += connection.second / 2;
                else new_cost += connection.second;
                ll prev_cost;
                prev_cost = marian_min[connection.first][has_horse];
                if (new_cost < prev_cost) {
                    marian_bfs.erase(make_pair(prev_cost, make_pair(connection.first, has_horse)));
                    marian_bfs.insert(make_pair(new_cost, make_pair(connection.first, has_horse)));
                    marian_min[connection.first][has_horse] = new_cost;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            min_time = min(min_time, max(min(robin_min[j][0], robin_min[j][1]), min(marian_min[j][0], marian_min[j][1])));
        }

        cout << (min_time == LLONG_MAX / 2 ? -1 : min_time) << endl;
    }
}
