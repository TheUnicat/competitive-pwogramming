//
// Created by TheUnicat on 2025-01-09.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, q;

vector<ll> node_idx, n_nodes, val, true_val, segtree;
vector<bool> visited;
vector<vector<int>> edges;

void update(int node, ll new_val) {
    node += n;
    segtree[node] = new_val;
    node /= 2;
    while (node > 0) {
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
        node /= 2;
    }
}

ll query(int l, int r) {
    ll sum = 0;
    l += n, r += n;
    while (r >= l) {
        if (l & 1) {
            sum += segtree[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += segtree[r];
            r--;
        }
        l /= 2, r /= 2;
    }

    return sum;
}

void dfs(int node) {
    visited[node] = true;
    true_val.push_back(val[node]);
    node_idx[node] = true_val.size() - 1;
    n_nodes[node] = 1;
    for (int edge : edges[node]) {
        if (!visited[edge]) {
            dfs(edge);
            n_nodes[node] += n_nodes[edge];
        }
    }
}

int main() {
    cin >> n >> q;
    val.resize(n), edges.resize(n), n_nodes.resize(n, 0), segtree.resize(2 * n, 0), node_idx.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0);
    for (int i = 0; i < n; i++) segtree[n + i] = true_val[i];
    for (int i = n - 1; i >= 0; i--) segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];

    for (int i = 0; i < q; i++) {
        int type, s, x;
        cin >> type >> s;
        s--;
        if (type == 1) cin >> x;
        if (type == 1) update(node_idx[s], x);
        else cout << query(node_idx[s], node_idx[s] + n_nodes[s] - 1) << endl;
    }
}