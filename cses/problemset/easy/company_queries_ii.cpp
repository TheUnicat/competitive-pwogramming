//
// Created by TheUnicat on 2025-01-12.
//

#include <iostream>
#include <vector>
using namespace std;

int n, q;
int depth = 0;
vector<vector<int>> bosses;
vector<int> euler, segtree, pos, depth_arr;
vector<bool> visited;

int query(int l, int r) {
    l += 2 * n - 1, r += 2 * n - 1;
    int ans = segtree[l];
    while (l <= r) {
        if (l & 1) {
            if (depth_arr[ans] > depth_arr[segtree[l]]) ans = segtree[l];
            l++;
        }
        if (r % 2 == 0) {
            if (depth_arr[ans] > depth_arr[segtree[r]]) ans = segtree[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return euler[ans];
}

void dfs(int node) {
    pos[node] = min(pos[node], (int) euler.size());
    visited[node] = true;
    euler.push_back(node);
    depth_arr.push_back(depth);
    depth++;
    for (int edge : bosses[node]) {
        if (!visited[edge]) {
            dfs(edge);
            depth_arr.push_back(depth - 1);
            euler.push_back(node);
        }
    }
    depth--;
}

int main() {
    cin >> n >> q;
    bosses.resize(n), visited.resize(n, false), pos.resize(n, 2 * n - 1), segtree.resize(2 * (2 * n - 1), 0);
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        b--;
        bosses[i].push_back(b);
        bosses[b].push_back(i);
    }
    dfs(0);

    for (int i = 0; i < 2 * n - 1; i++) {
        segtree[i + 2 * n - 1] = i;
    }

    for (int i = 2 * n - 2; i >= 1; i--) {
        if (depth_arr[segtree[i * 2]] < depth_arr[segtree[i * 2 + 1]]) {
            segtree[i] = segtree[i * 2];
        }
        else segtree[i] = segtree[i * 2 + 1];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << query(min(pos[a], pos[b]), max(pos[a], pos[b])) + 1 << endl;
    }
}