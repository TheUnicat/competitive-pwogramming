//
// Created by TheUnicat on 2025-01-22.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, depth = 0;
vector<int> ans, par;
vector<pair<int, int>> depth_arr;
vector<set<int>> sets;
vector<vector<int>> edges;

void dfs(int v, int p) {
    par[v] = p;
    depth_arr[v].first = depth;
    depth_arr[v].second = v;
    depth++;
    for (int edge : edges[v]) {
        if (edge != p) dfs(edge, v);
    }
    depth--;
}

int main() {
    cin >> n;
    edges.resize(n), ans.resize(n), depth_arr.resize(n), par.resize(n), sets.resize(n);
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        sets[i].insert(color);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    sort(depth_arr.begin(), depth_arr.end());
    for (int i = n - 1; i >= 0; i--) {
        int node = depth_arr[i].second;
        ans[node] = sets[node].size();
        if (par[node] == -1) continue;
        if (sets[par[node]].size() < sets[node].size()) {
            swap(sets[par[node]], sets[node]);
        }
        for (int num : sets[node]) sets[par[node]].insert(num);
    }

    for (int num : ans) cout << num << " ";
}