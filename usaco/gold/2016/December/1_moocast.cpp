//
// Created by TheUnicat on 2024-10-06.
//

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll n;
vector<pair<ll, ll>> cows;
vector<ll> groups;
vector<ll> c_size;

void init() {
    groups.resize(n);
    c_size.resize(n, 1);
    for (ll i = 0; i < n; i++) groups[i] = i;
}

ll group_of(ll node) {
    if (groups[node] == node) return node;
    groups[node] = group_of(groups[node]);
    return groups[node];
}

ll sq(ll a) {
    return a * a;
}

void unite(ll a, ll b) {
    ll a_group = group_of(a), b_group = group_of(b);
    if (a_group == b_group) return;
    if (c_size[a_group] > c_size[b_group]) {
        groups[b_group] = a_group;
        c_size[a_group] += c_size[b_group];
    }
    else {
        groups[a_group] = b_group;
        c_size[b_group] += c_size[a_group];
    }
}

bool strength_valid(ll strength) {
    init();
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (sq(cows[i].first - cows[j].first) + sq(cows[i].second - cows[j].second) <= strength) unite(i, j);
        }
    }
    int first_group = group_of(0);
    for (ll i = 0; i < n; i++) {
        if (group_of(i) != first_group) return false;
    }
    return true;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    cows.resize(n);
    for (ll i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;

    ll max_p = 2 * 25000 * 25000;
    ll min_p = 0;
    ll min_power_possible = -1;

    while (min_p <= max_p) {
        ll mid = min_p + (max_p - min_p) / 2;
        if (strength_valid(mid)) {
            min_power_possible = mid;
            max_p = mid - 1;
        }
        else min_p = mid + 1;
    }

    cout << min_power_possible;
}