//
// Created by TheUnicat on 2024-07-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<bool> searched;

void tree_segments(int start_node, const vector<vector<int> > &road_graph) {
    if (searched[start_node]) return;
    searched[start_node] = true;

    for (int edge : road_graph[start_node]) {
        tree_segments(edge - 1, road_graph);
    }
}

int main() {
    cin >> n >> m;
    searched.resize(n, false);
    vector<vector<int> > road_graph(n);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        road_graph[start - 1].push_back(end);
        road_graph[end - 1].push_back(start);
    }

    vector<int> connector_parts;
    auto it = searched.begin();
    while (true) {
        if (it == searched.end()) break;
        if (*it) {
            it++;
            continue;
        }
        tree_segments(distance(searched.begin(), it), road_graph);
        connector_parts.push_back(distance(searched.begin(), it) + 1);
        it++;
    }

    cout << connector_parts.size() - 1 << endl;
    for (int i = 1; i < connector_parts.size(); i++) {
        cout << connector_parts[i - 1] << " " << connector_parts[i] << endl;
    }
}