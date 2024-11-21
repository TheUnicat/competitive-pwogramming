#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
int max_component_size = 1;
vector<pair<ll, ll>> graph;
vector<int> component;
vector<pair<ll, int>> highest_x(11, {-1, -1});
vector<int> component_size;
priority_queue<pair<ll, pair<int, int>>> pq;

ll dist(int a, int b) {
    return (graph[a].first - graph[b].first) * (graph[a].first - graph[b].first) + (graph[a].second - graph[b].second) * (graph[a].second - graph[b].second);
}

void init() {
    component.resize(n);
    component_size.resize(n, 1);
    for (int i = 0; i < n; i++) component[i] = i;
}

int find_component(int node) {
    if (component[node] == node) return node;
    component[node] = find_component(component[node]);
    return component[node];
}

void unite(int a, int b) {
    int a_c = find_component(a), b_c = find_component(b);
    if (component_size[a_c] > component_size[b_c]) {
        component[b_c] = a_c;
        component_size[a_c] += component_size[b_c];
        max_component_size = max(max_component_size, component_size[a_c]);
    }
    else {
        component[a_c] = b_c;
        component_size[b_c] += component_size[a_c];
        max_component_size = max(max_component_size, component_size[b_c]);
    }
}

void add_edges(int curr) {
    ll curr_x = graph[curr].first, curr_y = graph[curr].second;
    for (int i = 0; i < 11; i++) {
        if (highest_x[i].first == -1) continue;
        pq.emplace(-((curr_y - i) * (curr_y - i) + (curr_x - highest_x[i].first) * (curr_x - highest_x[i].first)), make_pair(highest_x[i].second, curr));
    }
    highest_x[curr_y].first = curr_x;
    highest_x[curr_y].second = curr;
}

int main() {
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph.emplace_back(x, y);
    }
    sort(graph.begin(), graph.end());
    for (int i = 0; i < n; i++) add_edges(i);

    ll total_cost = 0;
    while (max_component_size < n) {
        auto top = pq.top();
        pq.pop();
        ll cost = top.first;
        int x = top.second.first, y = top.second.second;
        if (find_component(x) != find_component(y)) {
            unite(find_component(x), find_component(y));
            total_cost += cost;
        }
    }

    cout << -total_cost;
}