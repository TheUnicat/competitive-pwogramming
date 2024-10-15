//
// Created by TheUnicat on 2024-10-15.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    int mod_n = 1000000007;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<int> paths(n, 0);
    paths[0] = 1;
    vector<int> indegree(n, 0);
    vector<bool> visited(n, false);
    vector<int> sorted;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b - 1]++;
        edges[a - 1].push_back(b - 1);
    }

    queue<int> kahn;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) {
            kahn.push(i);
            visited[i] = true;
        }

    while (!kahn.empty()) {
        int top = kahn.front();
        visited[top] = true;
        sorted.push_back(top);
        kahn.pop();
        for (int connection : edges[top]) {
            if (visited[connection]) continue;
            indegree[connection]--;
            if (indegree[connection] == 0) kahn.push(connection);
        }
    }

    for (int node : sorted) {
        for (int edge : edges[node]) {
            paths[edge] += paths[node];
            paths[edge] %= mod_n;
        }
    }

    cout << paths[n - 1];
}