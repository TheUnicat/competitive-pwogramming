//
// Created by TheUnicat on 2024-07-31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> color;
vector<vector<int> > edges;

bool dfs(int start_node, int c) {
    if (color[start_node] != 0) return color[start_node] == c;
    color[start_node] = c;

    for (int adj : edges[start_node]) {
        if (!dfs(adj - 1, 3 - c)) return false;
    }

    return true;
}

int main() {
    cin >> n >> m;
    color.resize(n, 0);
    edges.resize(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        edges[start - 1].push_back(end);
        edges[end - 1].push_back(start);
    }
    auto it = color.begin();
    while (it != color.end()) {
        if (*it == 0) {
            bool valid = dfs(distance(color.begin(), it), 1);
            if (!valid) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        it++;
    }

    for (int i = 0; i < n; i++) cout << color[i] << " ";
}