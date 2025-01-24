//
// Created by TheUnicat on 2025-01-23.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> ans_inclusive, ans_exclusive;

void dfs(int v, int p) {
    int min_diff = 1e9, sum = 0;
    for (int edge : edges[v]) {
        if (edge == p) continue;
        if (ans_inclusive[edge] == -1) dfs(edge, v);
        sum += max(ans_inclusive[edge], ans_exclusive[edge]);
        min_diff = min(min_diff, ans_inclusive[edge] - ans_exclusive[edge]);
    }
    ans_exclusive[v] = sum;
    if (min_diff == 0) ans_inclusive[v] = sum + 1;
    else ans_inclusive[v] = sum;
}

int main() {
    cin >> n;
    edges.resize(n), ans_inclusive.resize(n, -1), ans_exclusive.resize(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans_inclusive[0] << endl;
}