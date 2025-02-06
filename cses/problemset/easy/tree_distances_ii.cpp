//
// Created by TheUnicat on 2025-02-05.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<int> subtree_sizes;
vector<ll> distances;
vector<vector<int>> edges;

void dfs(int v, int p) {
    for (int c : edges[v]) {
        if (c == p) continue;
        dfs(c, v);
        subtree_sizes[v] += subtree_sizes[c];
        distances[v] += distances[c] + subtree_sizes[c];
    }
}

void dfs2(int v, int p) {
    for (int c : edges[v]) {
        if (c == p) continue;
        distances[c] = distances[v] + (n - subtree_sizes[c]) - (subtree_sizes[c]);
        dfs2(c, v);
    }
}

int main() {
    cin >> n;
    edges.resize(n), distances.resize(n, 0), subtree_sizes.resize(n, 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; i++) cout << distances[i] << endl;
}