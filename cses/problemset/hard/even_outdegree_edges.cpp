//
// Created by TheUnicat on 2024-08-04.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<pair<int, bool> > > graph;

int main() {
    cin >> n >> m;
    graph.resize(n, vector<pair<int, bool> >());
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start - 1].push_back(make_pair(end - 1, false));
        graph[end - 1].push_back(make_pair(start - 1, false));
    }

    for (int i = 0; i < n; i++) {
        int outdegrees = 0;
        int edge_count = graph[i].size();
        for (int j = 0; j < edge_count; j++) {
            auto edge = graph[i][j];
            if (edge.second) continue;
            if (edge.first == i) {
                graph[i][j].second = true;
                outdegrees++;
            }
            if (graph[i].size() == 1) {
                graph[edge.first]
            }
        }
    }
}
