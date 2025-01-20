//
// Created by TheUnicat on 2025-01-16.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int n, q, timer = 1, d = 0, log_n;
vector<int> in, out, depth, fenwick, values;
vector<vector<int>> par, edges;
vector<bool> visited;

int lsb(int num) {
    return num & -num;
}

void update(int pos, int val) {
    while (pos <= 2 * n + 1) {
        fenwick[pos] ^= val;
        pos += lsb(pos);
    }
}

int query(int time) {
    int ans = 0;
    while (time > 0) {
        ans ^= fenwick[time];
        time -= lsb(time);
    }
    return ans;
}

void dfs(int node, int parent) {
    if (visited[node]) return;
    visited[node] = true;
    par[node][0] = parent;
    for (int i = 1; i < log_n; i++) {
        if (par[node][i - 1] == -1) break;
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    in[node] = timer;
    update(timer, values[node]);
    timer++;
    depth[node] = d;
    d++;
    for (int edge : edges[node]) {
        if (!visited[edge]) {
            dfs(edge, node);
        }
    }
    d--;
    out[node] = timer++;
    update(timer, values[node]);
}

int lca(int a, int b) {
    if (depth[b] < depth[a]) {
        int temp = b;
        b = a;
        a = temp;
    }

    int diff = depth[b] - depth[a];
    for (int i = 0; i < log_n; i++) {
        if (diff & (1 << i)) b = par[b][i];
    }
    if (a == b) return a;

    for (int i = log_n - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i], b = par[b][i];
        }
    }
    return par[a][0];
}


int main() {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> n >> q;
    log_n = (int) log2(n);
    visited.resize(n, false), in.resize(n), out.resize(n), depth.resize(n), fenwick.resize(2 * n + 2, 0), values.resize(n);
    edges.resize(n), par.resize(n, vector<int>(log_n, -1));
    for (int i = 0; i < n; i++) cin >> values[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b), edges[b].push_back(a);
    }
    dfs(0, -1);

    for (int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            a--;
            update(in[a], values[a]);
            update(out[a], values[a]);
            values[a] = b;
            update(in[a], values[a]);
            update(out[a], values[a]);
        }
        else {
            a--, b--;
            cout << (values[lca(a, b)] ^ query(in[b]) ^ query(in[a])) << endl;
        }
    }
}