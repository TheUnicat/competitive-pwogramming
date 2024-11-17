//
// Created by TheUnicat on 2024-11-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

//toggle solution mode to "math" or "kruskal" (TLEs)
string mode = "math";

ll ans;
int n, k;
ll x_val = 2019201913, y_val = 2019201949;
ll mod_val = 2019201997;
vector<pair<ll, pair<int, int>>> edges;

vector<int> component;
vector<int> cc_size;
vector<ll> x_vals, y_vals;

void init() {
    x_vals.resize(n);
    y_vals.resize(n);
    ll curr_x = 0, curr_y = 0;
    for (int i = 0; i < n; i++) {
        curr_x += x_val;
        curr_x %= mod_val;
        x_vals[i] = curr_x;
        curr_y += y_val;
        curr_y %= mod_val;
        y_vals[i] = curr_y;
    }

    cc_size.resize(n, 1);
    component.resize(n);
    for (int i = 0; i < n; i++) component[i] = i;
}

int find_component(int n) {
    if (component[n] == n) return n;
    component[n] = find_component(component[n]);
    return component[n];
}

void unite(int a, int b) {
    int a_c = find_component(a), b_c = find_component(b);
    if (cc_size[a_c] > cc_size[b_c]) {
        component[b_c] = a_c;
        cc_size[a_c] += cc_size[b_c];
    }
    else {
        component[a_c] = b_c;
        cc_size[b_c] += cc_size[a_c];
    }
}

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    cin >> n >> k;
    if (mode == "kruskal") {
        init();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll edge_cost = x_vals[i] + y_vals[j];
                edge_cost %= mod_val;
                edges.emplace_back(edge_cost, make_pair(i, j));
            }
        }

        sort(edges.begin(), edges.end());
        int count = 0;
        for (auto edge : edges) {
            if (count == n - k) {
                if (find_component(edge.second.first) != find_component(edge.second.second)) {
                    ans = edge.first;
                    break;
                }
                continue;
            }

            if (find_component(edge.second.first) != find_component(edge.second.second)) {
                unite(edge.second.first, edge.second.second);
                count++;
            }
        }
    }
    else if (mode == "math") {
        ans = mod_val - 84 * (k - 1) - 48 * n;
    }

    cout << ans << endl;
}