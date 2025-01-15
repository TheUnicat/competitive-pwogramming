//
// Created by TheUnicat on 2025-01-12.
//

#include <iostream>
#include <vector>
using namespace std;

int n, q, euler_size;
vector<int> depth, segtree, pos;
vector<vector<int>> edges;
vector<bool> visited;
int timer = 0;

int min_depth(int l, int r) {
    l += euler_size, r += euler_size;
    int ans = segtree[l];
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, segtree[l]);
            l++;
        }
        if (r % 2 == 0) {
            ans = min(ans, segtree[r]);
            r--;
        }
        l /= 2, r /= 2;
    }

    return ans;
}

void dfs(int node, int d) {
    visited[node] = true;
    pos[node] = min(pos[node], timer);
    timer++;
    depth.push_back(d);
    for (int edge : edges[node]) {
        if (!visited[edge]) {
            dfs(edge, d + 1);
            depth.push_back(d);
            timer++;
        }
    }
}

int main() {
    cin >> n >> q;
    euler_size = 2 * n - 1;
    edges.resize(n), pos.resize(n, 1e9), segtree.resize(2 * euler_size, 0);
    visited.resize(n, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, 0);

    for (int i = 0; i < euler_size; i++) segtree[euler_size + i] = depth[i];
    for (int i = euler_size - 1; i >= 0; i--) segtree[i] = min(segtree[i * 2], segtree[i * 2 + 1]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int lca_depth = min_depth(min(pos[a], pos[b]), max(pos[a], pos[b]));
        cout << depth[pos[a]] + depth[pos[b]] - 2 * lca_depth << endl;
    }
}