//
// Created by TheUnicat on 2024-07-19.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m;
vector<int> positions;
vector<pair<int, pair<int, int>>> wormholes;
vector<int> groups;
vector<int> component_size;

void init() {
    groups.resize(n);
    component_size.resize(n, 1);
    for (int i = 0; i < n; i++) groups[i] = i;
}

int group_of(int node) {
    if (groups[node] == node) return node;
    groups[node] = group_of(groups[node]);
    return groups[node];
}

void unite(int a, int b) {
    int a_group = group_of(a), b_group = group_of(b);
    if (component_size[a_group] > component_size[b_group]) {
        groups[b_group] = groups[a_group];
    }
    else groups[a_group] = groups[b_group];
}

bool index_works(int min_width) {
    init();
    for (int i = 0; i < m; i++) {
        if (wormholes[i].first < min_width) break;
        unite(wormholes[i].second.first, wormholes[i].second.second);
    }
    for (int i = 0; i < n; i++) {
        if (group_of(i) != group_of(positions[i])) return false;
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    positions.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
        positions[i]--;
    }

    bool no_wormholes_needed = true;
    for (int i = 0; i < n; i++) {
        if (positions[i] != i) {
            no_wormholes_needed = false;
            break;
        }
    }

    if (no_wormholes_needed) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        wormholes.emplace_back(w, make_pair(a, b));
    }
    sort(wormholes.rbegin(), wormholes.rend());

    int min_val = 0;
    int max_val = wormholes[0].first;
    int max_sol = -2;
    while (max_val >= min_val) {
        int mid = min_val + (max_val - min_val) / 2;
        if (index_works(mid)) {
            max_sol = mid;
            min_val = mid + 1;
        }
        else max_val = mid - 1;
    }

    cout << max_sol;
}