//
// Created by TheUnicat on 2025-02-05.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> max_len, max_len_2, max_len_no_max;

void dfs(int v, int p) {
    max_len[v] = 0;
    for (int c : edges[v]) {
        if (c == p) continue;
        dfs(c, v);
        if (max_len[c] + 1 > max_len[v]) {
            max_len_no_max[v] = max_len[v];
            max_len[v] = max_len[c] + 1;
        }
        else if (max_len[c] + 1 > max_len_no_max[v]) {
            max_len_no_max[v] = max_len[c] + 1;
        }
    }
}

void dfs2(int v, int p) {
    for (int c : edges[v]) {
        if (c == p) continue;
        if (max_len[c] != max_len[v] - 1) max_len_2[c] = max(max_len_2[v] + 1, max_len[v] + 1);
        else max_len_2[c] = max(max_len_2[v] + 1, max_len_no_max[v] + 1);
        dfs2(c, v);
    }
}

int main() {
    cin >> n;
    edges.resize(n), max_len.resize(n, -1), max_len_2.resize(n, 0), max_len_no_max.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; i++) cout << max(max_len[i], max_len_2[i]) << endl;
}