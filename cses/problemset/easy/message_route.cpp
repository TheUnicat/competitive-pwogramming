//
// Created by TheUnicat on 2024-09-23.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> dijkstra;


int main() {
    cin >> n >> m;
    graph.resize(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    dijkstra.resize(n, INT32_MAX);
    dijkstra[n - 1] = 0;

    queue<int> bfs;
    bfs.push(n - 1);
    while (!bfs.empty()) {
        for (int node : graph[bfs.front()]) {
            if (dijkstra[node] > dijkstra[bfs.front()] + 1) {
                dijkstra[node] = dijkstra[bfs.front()] + 1;
                bfs.push(node);
            }
        }
        bfs.pop();
    }

    if (dijkstra[0] == INT32_MAX) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dijkstra[0] + 1 << endl;
    int curr_node = 0;
    int curr_distance = dijkstra[0];
    while (curr_node != n - 1) {
        cout << curr_node + 1 << " ";
        for (int node : graph[curr_node]) {
            if (dijkstra[node] == curr_distance - 1) {
                curr_node = node;
                --curr_distance;
                break;
            }
        }
    }
    cout << n;
}