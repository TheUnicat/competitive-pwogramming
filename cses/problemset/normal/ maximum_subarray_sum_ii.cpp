//
// Created by TheUnicat on 2024-11-30.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int n, a, b;
vector<ll> prefix_sums;
multiset<ll> window;

int main() {
    cin >> n >> a >> b;
    prefix_sums.resize(n + 1);
    ll curr_sum = 0;

    prefix_sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll num;
        cin >> num;
        curr_sum += num;
        prefix_sums[i] = curr_sum;
    }

    for (int i = a; i <= b; i++) {
        window.insert(prefix_sums[i]);
    }
    auto it = window.end();
    it--;
    ll max_sliding_window_sum = *it - prefix_sums[0];

    for (int i = 1; i <= n - a; i++) {
        if (true) window.erase(window.find((prefix_sums[i + a - 1])));
        if (i + b <= n) window.insert(prefix_sums[i + b]);
        auto new_it = window.end();
        --new_it;
        max_sliding_window_sum = max(max_sliding_window_sum, (*new_it) - prefix_sums[i]);
    }

    cout << max_sliding_window_sum << endl;
}