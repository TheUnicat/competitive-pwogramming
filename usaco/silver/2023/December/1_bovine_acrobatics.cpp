//
// Created by TheUnicat on 2024-12-10.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
using ll = long long;

ll n, m, k;
set<pair<ll, ll>> cows;
deque<pair<ll, ll>> towers;
ll ans = 0;
ll n_towers = 0;

int main() {
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++) {
        ll w, a;
        cin >> w >> a;
        cows.emplace(-w, a);
    }

    auto it = cows.begin();
    while (it != cows.end()) {
        ll n_to_add = 0;
        ll height = -(*it).first, num = (*it).second;
        if (n_towers < m) {
            n_to_add += min(m - n_towers, num);
            num -= n_to_add;
            ans += n_to_add;
            n_towers += n_to_add;
        }
        while (num > 0) {
            if ((!towers.empty()) && towers.front().first - k >= height) {
                auto first = towers.front();
                ll cows_modified = min(first.second, num);
                ll orig_cows = first.second;
                ll orig_height = first.first;
                towers.pop_front();
                if (orig_cows - cows_modified > 0) {
                    towers.emplace_front(orig_height, orig_cows - cows_modified);
                }
                n_to_add += cows_modified;
                num -= cows_modified;
                ans += cows_modified;
            }
            else {
                break;
            }
        }
        towers.emplace_back(height, n_to_add);
        it++;
    }

    cout << ans << endl;
}