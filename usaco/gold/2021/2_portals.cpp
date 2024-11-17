//
// Created by TheUnicat on 2024-11-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll n;
vector<ll> component;
vector<ll> cc_size;
vector<pair<ll, pair<ll, ll>>> edge_list;

void init() {
    component.resize(2 * n);
    cc_size.resize(2 * n, 1);
    for (ll i = 0; i < 2 * n; i++) component[i] = i;
}

ll component_of(ll portal) {
    if (component[portal] == portal) return portal;
    component[portal] = component_of(component[portal]);
    return component[portal];
}

void unite(ll a, ll b) {
    auto a_component = component_of(a), b_component = component_of(b);
    ll a_size = cc_size[a], b_size = cc_size[b];
    if (a_size < b_size) {
        component[a] = b_component;
        cc_size[b] += a_size;
    }
    else {
        component[b] = a_component;
        cc_size[a] += b_size;
    }
}

int main() {
    ll cost = 0;
    cin >> n;
    init();
    for (ll i = 0; i < n; i++) {
        ll c, p1, p2, p3, p4;
        cin >> c >> p1 >> p2 >> p3 >> p4;
        p1--, p2--, p3--, p4--;
        edge_list.emplace_back(0, make_pair(p1, p2));
        edge_list.emplace_back(0, make_pair(p3, p4));
        edge_list.emplace_back(c, make_pair(p1, p3));
    }

    sort(edge_list.begin(), edge_list.end());
    for (auto edge : edge_list) {
        auto first_component = component_of(edge.second.first), second_component = component_of(edge.second.second);
        if (first_component != second_component) {
            unite(first_component, second_component);
            cost += edge.first;
        }
    }

    cout << cost;
}