//
// Created by TheUnicat on 2024-10-12.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> in_stack;
vector<int> parent;
stack<int> answer;

int main() {
    cin >> n >> m;
    graph.resize(n);
    parent.resize(n, -1);
    int cycle_node = -1;
    visited.resize(n, false);
    in_stack.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++) {
        if (cycle_node != -1) break;
        if (!visited[i]) {
            stack<int> dfs;
            dfs.push(i);
            in_stack[i] = true;
            while (!dfs.empty()) {
                if (cycle_node != -1) break;
                int top = dfs.top();
                visited[top] = true;
                bool add = false;
                for (int node : graph[top]) {
                    if (in_stack[node]) {
                        parent[node] = top;
                        cycle_node = node;
                        break;
                    }
                    if (!visited[node]) {
                        dfs.push(node);
                        parent[node] = top;
                        in_stack[node] = true;
                        add = true;
                        break;
                    }
                }

                if (!add) {
                    answer.push(top);
                    dfs.pop();
                    in_stack[top] = false;
                }
            }
        }
    }

    if (cycle_node == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    stack<int> unwind;
    unwind.push(cycle_node);
    int curr_node = parent[cycle_node];
    while (curr_node != cycle_node) {
        unwind.push(curr_node);
        curr_node = parent[curr_node];
    }

    unwind.push(cycle_node);
    cout << unwind.size() << endl;
    while (!unwind.empty()) {
        cout << unwind.top() + 1 << " ";
        unwind.pop();
    }
}