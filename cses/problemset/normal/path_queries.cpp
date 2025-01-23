//
// Created by TheUnicat on 2025-01-21.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, q, timer = 1, curr_depth = 0;
vector<int> in, out;
vector<ll> fenwick, values;
vector<vector<int>> edges;

int lsb(int num) {
    return num & - num;
}

void update(int idx, ll value) {
    while (idx < 2 * n + 2) {
        fenwick[idx] += value;
        idx += lsb(idx);
    }
}

ll query(int idx) {
    ll ans = 0;
    while (idx >= 0) {
        ans += fenwick[idx];
        if (idx == 0) break;
        idx -= lsb(idx);
    }
    return ans;
}

void dfs(int node, int p) {
    in[node] = timer;
    update(timer, values[node]);
    timer++;
    curr_depth++;
    for (int edge : edges[node]) {
        if (edge != p) dfs(edge, node);
    }
    out[node] = timer++;
    update(timer, -values[node]);
}


int main() {
    cin >> n >> q;
    in.resize(n), out.resize(n), fenwick.resize(2 * n + 2, 0), values.resize(n);
    edges.resize(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a;
        if (type == 1) {
            cin >> b;
            a--;
            update(in[a], -values[a] + b);
            update(out[a] + 1, values[a] - b);
            values[a] = b;
        }
        else {
            a--;
            cout << query(in[a]) << endl;
        }
    }
}