//
// Created by TheUnicat on 2024-12-13.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t, n, m;
vector<int> components;
vector<vector<int>> edges;

void color(int idx) {
    for (int node : edges[idx]) {
        if (components[node] != -1) continue;
        components[node] = components[idx];
        color(node);
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int connected_components = 0;
        cin >> n >> m;
        edges.clear();
        edges.resize(n);
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        components.clear();
        components.resize(n, -1);
        for (int j = 0; j < n; j++) {
            if (components[j] == -1) {
                components[j] = connected_components;
                color(j);
                connected_components++;
            }
            //cout << components[j] << " ";
        }
       // cout << endl;
        vector<ll> first_closest(connected_components, 1e18);
        vector<ll> second_closest(connected_components, 1e18);
        vector<int> last_seen(connected_components, -1);
        int first_c = components[0], second_c = components[n - 1];
        vector<int> updated_first, updated_second;
        for (int j = 0; j < n; j++) {
            int curr_c = components[j];
            last_seen[curr_c] = j;
            updated_first.push_back(curr_c);
            updated_second.push_back(curr_c);
            if (last_seen[first_c] != -1) {
                first_closest[curr_c] = min(first_closest[curr_c], ((ll) (j - last_seen[first_c]))* (j - last_seen[first_c]));
            }
            if (last_seen[second_c] != -1) {
                second_closest[curr_c] = min(second_closest[curr_c], ((ll) (j - last_seen[second_c])) * (j - last_seen[second_c]));
            }
            if (curr_c == first_c) {
                for (auto k : updated_first) {
                    if (last_seen[k] == -1) continue;
                    first_closest[k] = min(first_closest[k], ((ll) last_seen[k] - j) * (last_seen[k] - j));
                }
            }
            if (curr_c == second_c) {
                for (auto k : updated_second) {
                    if (last_seen[k] == -1) continue;
                    second_closest[k] = min(second_closest[k], ((ll) last_seen[k] - j) * (last_seen[k] - j));
                }
            }

            if (curr_c == first_c) updated_first.clear();
            else if (curr_c == second_c) updated_second.clear();
        }

        if (first_c == second_c) cout << 0 << endl;
        else {
            ll min_cost = 1e18;
            for (int j = 0; j < connected_components; j++) {
                min_cost = min(min_cost, first_closest[j] + second_closest[j]);
            }
            cout << min_cost << endl;
        }
    }
}