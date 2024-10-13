//
// Created by TheUnicat on 2024-10-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> paths;
vector<int> parent;
vector<vector<int>> flights;
vector<bool> visited;
vector<int> sorted;

int n, m;
void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (int connection : flights[node]) dfs(connection);
    sorted.push_back(node);
}

int main() {
    cin >> n >> m;
    paths.resize(n, -1);
    visited.resize(n, false);
    parent.resize(n);
    paths[0] = 1;
    flights.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        flights[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    reverse(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++) {
        if (paths[sorted[i]] <= 0) continue;
        for (int node : flights[sorted[i]]) {
            if (paths[node] < paths[sorted[i]] + 1) {
                paths[node] = paths[sorted[i]] + 1;
                parent[node] = sorted[i];
            }
        }
    }


    if (paths[n - 1] <= 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << paths[n - 1] << endl;
    vector<int> history;
    int curr_node = n - 1;
    while (curr_node != 0) {
        history.push_back(curr_node);
        curr_node = parent[curr_node];
    }
    history.push_back(0);
    reverse(history.begin(), history.end());
    for (int node : history) cout << node + 1 << " ";
}