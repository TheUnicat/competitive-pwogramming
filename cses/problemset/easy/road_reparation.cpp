//
// Created by TheUnicat on 2024-11-11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<pair<int, pair<int, int>>> edge_list;
vector<int> graph;
vector<int> component_size;

void init() {
    graph.resize(n);
    component_size.resize(n, 1);
    for (int i = 0; i < n; i++) graph[i] = i;
}

int find_component(int n) {
    if (graph[n] == n) return n;
    int component = find_component(graph[n]);
    graph[n] = component;
    return component;
}

void add_edge(int a, int b) {
    if (graph[a] == graph[b]) return;
    int a_component = find_component(a), b_component = find_component(b);
    if (component_size[a_component] < component_size[b_component]) {
        graph[a_component] = b_component;
        component_size[b_component] += component_size[a_component];
    }
    else {
        graph[b_component] = a_component;
        component_size[a_component] += component_size[b_component];
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.emplace_back(c, make_pair(a - 1, b - 1));
    }

    sort(edge_list.begin(), edge_list.end());
    ll total_cost = 0;
    for (auto edge : edge_list) {
        int a = edge.second.first, b = edge.second.second, c = edge.first;
        if (find_component(a) != find_component(b)) {
            add_edge(a, b);
            total_cost += c;
        }
    }

    int max_component_size = 0;
    for (int val : component_size) max_component_size = max(max_component_size, val);
    if (max_component_size != n) {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        cout << total_cost << endl;
}