//
// Created by TheUnicat on 2024-07-31.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > routes_graph;
vector<vector<int> > inverted_graph;
vector<bool> searched;

int dfs(int start_city, const vector<vector<int> > &graph) {
    int count = 0;
    if (searched[start_city]) return count;
    searched[start_city] = true;
    count++;

    for (int connection : graph[start_city]) {
        count += dfs(connection, graph);
    }

    return count;
}

int main() {
    cin >> n >> m;
    routes_graph.resize(n, vector<int>());
    inverted_graph.resize(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        routes_graph[start - 1].push_back(end - 1);
        inverted_graph[end - 1].push_back(start - 1);
    }


    searched.clear();
    searched.resize(n, false);
    int n_reached = dfs(0, routes_graph);
    if (n_reached != n) {
        for (int i = 1; i < n; i++) {
            if (searched[i] == false) {
                cout << "NO" << endl << 1 << " " << i + 1;
                return 0;
            }
        }
    }
    searched.clear();
    searched.resize(n, false);
    n_reached = dfs(0, inverted_graph);
    if (n_reached != n) {
        for (int i = 1; i < n; i++) {
            if (searched[i] == false) {
                cout << "NO" << endl <<  i + 1 << " " << 1;
                return 0;
            }
        }
    }

    cout << "YES";
}

