//
// Created by TheUnicat on 2024-11-11.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int A, B, n = 0, m = 0;
vector<pair<int, pair<int, int>>> edge_list;
vector<int> components;
vector<int> vertical, horizontal;
vector<int> component_size;

void init() {
    components.resize((n + 1) * (m + 1));
    for (int i = 0; i < (n + 1) * (m + 1); i++) components[i] = i;
    component_size.resize((n + 1) * (m + 1), 1);
}

int find_component(int n) {
    if (components[n] == n) {
        return n;
    }
    int component = find_component(components[n]);
    components[n] = component;
    return component;
}

void unite(int a, int b) {
    int a_component = find_component(a), b_component = find_component(b);
    if (a_component == b_component) return;

    if (component_size[a_component] < component_size[b_component]) {
        components[a_component] = b_component;
        component_size[b_component] += component_size[a_component];
    }
    else {
        components[b_component] = a_component;
        component_size[a_component] += component_size[b_component];
    }
}

int main() {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin >> A >> B >> n >> m;
    init();

    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        vertical.push_back(pos);
    }
    sort(vertical.begin(), vertical.end());
    vertical.push_back(A);
    for (int i = 0; i < m; i++) {
        int pos;
        cin >> pos;
        horizontal.push_back(pos);
    }
    sort(horizontal.begin(), horizontal.end());
    horizontal.push_back(B);

    int prev_x = 0, prev_y = 0;
    for (int i = 0; i <= n; i++) {
        int field = i - (n + 1);
        int vertical_cost = vertical[i] - prev_y;
        prev_y = vertical[i];
        prev_x = 0;
        for (int j = 0; j <= m; j++) {
            field += n + 1;
            if (j != m) edge_list.emplace_back(vertical_cost, make_pair(field, field + n + 1));
            if (i != n) edge_list.emplace_back(horizontal[j] - prev_x, make_pair(field, field + 1));
            prev_x = horizontal[j];
        }
    }

    sort(edge_list.begin(), edge_list.end());

    ll cost = 0;
    int count = 0;
    for (auto edge : edge_list) {
        if (count == (n + 1) * (m + 1) - 1) break;
        if (find_component(edge.second.first) != find_component(edge.second.second)) {
            unite(edge.second.first, edge.second.second);
            cost += edge.first;
            count++;
        }
    }

    cout << cost;
}

