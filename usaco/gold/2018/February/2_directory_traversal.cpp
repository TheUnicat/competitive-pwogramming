//
// Created by TheUnicat on 2025-02-06.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int n;
int file_count = 0;
vector<vector<int>> edges;
vector<ll> subtree_size, distance_ll, name_len;
vector<bool> is_dir;

void dfs(int v, int p) {
    for (int c : edges[v]) {
        if (c == p) continue;
        dfs(c, v);
        subtree_size[v] += subtree_size[c];
        distance_ll[v] += distance_ll[c] + subtree_size[c] * (name_len[c] + 1);
        if (edges[c].size() == 1) distance_ll[v]--;
    }
}

void dfs2(int v, int p) {
    for (int c : edges[v]) {
        if (c == p) continue;
        distance_ll[c] = distance_ll[v] + (file_count - subtree_size[c]) * 3 - subtree_size[c] * (name_len[c] + 1);
        dfs2(c, v);
    }
}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    cin >> n;
    edges.resize(n);
    is_dir.resize(n, false), subtree_size.resize(n, 0), distance_ll.resize(n, 0), name_len.resize(n);
    is_dir[0] = true;
    for (int i = 0; i < n; i++) {
        string name;
        int len;
        cin >> name >> len;
        name_len[i] = (ll) name.length();
        if (len > 0) is_dir[i] = true;
        if (len == 0) subtree_size[i] = 1;
        if (len == 0) file_count++;
        for (int j = 0; j < len; j++) {
            int target;
            cin >> target;
            edges[i].push_back(target - 1);
            edges[target - 1].push_back(i);
        }
    }
    dfs(0, -1);
    dfs2(0, -1);
    ll min_dist = 1e18;
    for (int i = 0; i < n; i++) if (is_dir[i]) min_dist = min(min_dist, distance_ll[i]);
    cout << min_dist << endl;
}