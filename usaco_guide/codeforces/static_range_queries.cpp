//
// Created by TheUnicat on 2024-07-20.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int n, q;
map<int, ll> updates;
vector<pair<int, int> > queries;
vector<pair<int, ll> > prefix_sums;
vector<pair<int, ll> >  range_sums;

ll find_range_sum(int l, int r) {
    ll l_sum = 0, r_sum = 0;

    auto it = lower_bound(range_sums.begin(), range_sums.end(), make_pair(l, 0LL));
    l_sum = it->second;

    it = lower_bound(range_sums.begin(), range_sums.end(), make_pair(r, 0LL));
    r_sum = it->second;

    return r_sum - l_sum;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        updates[l] += v;
        updates[r] -= v;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        updates[l] += 0;
        updates[r] += 0;
        queries.push_back(make_pair(l, r));
    }

    ll sum = 0;
    prefix_sums.push_back(make_pair(0, 0));
    for (const auto &update : updates) {
        sum += update.second;
        prefix_sums.push_back(make_pair(update.first, sum));
    }
    prefix_sums.push_back(make_pair(1000000000, prefix_sums.back().second));

    ll range_sum = 0;
    for (int j = 0; j < prefix_sums.size() - 1; j++) {
        range_sum += (prefix_sums[j + 1].first - prefix_sums[j].first) * prefix_sums[j].second;
        range_sums.push_back(make_pair(prefix_sums[j + 1].first, range_sum));
    }

    for (pair<int, int> query : queries) {
        cout << find_range_sum(query.first, query.second) << endl;
    }
}
