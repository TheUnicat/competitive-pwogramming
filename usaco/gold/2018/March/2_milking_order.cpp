//
// Created by TheUnicat on 2024-10-21.
//

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> observations;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> curr_sorted;

//make graph for first x observations
void make_graph(int x) {
    graph.clear();
    graph.resize(n);
    indegree.clear();
    indegree.resize(n, 0);
    curr_sorted.clear();
    for (int i = 0; i < x; i++) {
        int len = (int) observations[i].size();
        for (int j = 0; j < len - 1; j++) {
            graph[observations[i][j]].push_back(observations[i][j + 1]);
            indegree[observations[i][j + 1]]++;
        }
    }
}

bool kahn() {
    priority_queue<int, vector<int>, greater<int>> bfs;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            bfs.push(i);
        }
    }

    while (!bfs.empty()) {
        int top = bfs.top();
        curr_sorted.push_back(top);
        bfs.pop();
        for (int node : graph[top]) {
            indegree[node]--;
            if (indegree[node] == 0) bfs.push(node);
        }
    }

    if (curr_sorted.size() != n) return false;
    return true;
}


int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> n >> m;
    observations.resize(m);
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int num;
            cin >> num;
            observations[i].push_back(num - 1);
        }
    }
    int min_x = 0;
    int max_x = m;
    vector<int> min_sol;

    while (max_x >= min_x) {
        int mid = min_x + (max_x - min_x) / 2;
        make_graph(mid);
        if (kahn()) {
            min_sol = curr_sorted;
            min_x = mid + 1;
        }
        else max_x = mid - 1;
    }

    for (int i = 0; i < n; i++) {
        cout << min_sol[i] + 1;
        if (i != n - 1) cout << " ";
    }
}