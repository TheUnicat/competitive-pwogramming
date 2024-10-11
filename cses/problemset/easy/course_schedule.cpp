//
// Created by TheUnicat on 2024-10-08.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
stack<int> answer;
bool unsolvable = false;

int main() {
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++) {
        if (unsolvable) break;
        if (!visited[i]) {
            vector<bool> visited_cycle(n, false);
            stack<int> dfs;
            dfs.push(i);
            while (!empty(dfs)) {
                int top = dfs.top();
                visited[top] = true;
                visited_cycle[top] = true;
                bool done = true;
                for (int node : graph[top]) {
                    if (visited_cycle[node]) {
                        unsolvable = true;
                        break;
                    }
                    if (!visited[node]) {
                        done = false;
                        dfs.push(node);
                        break;
                    }
                }

                if (done) {
                    answer.push(top);
                    dfs.pop();
                    visited_cycle[top] = false;
                }
            }
        }
    }

    if (unsolvable) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    else {
        while (!answer.empty()) {
            cout << answer.top() + 1 << " ";
            answer.pop();
        }
    }
}