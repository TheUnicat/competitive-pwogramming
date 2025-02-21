//
// Created by TheUnicat on 2025-02-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
ll x;
vector<ll> sums_one, sums_two;
vector<pair<ll, ll>> c_one, c_two;

int main() {
    cin >> n >> x;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < (1 << min(20, n)); i++) {
        ll sum = 0;
        for (int k = 0; k < min(n, 20); k++) if ((1 << k) & i) sum += nums[k];
        if (sum <= x) sums_one.push_back(sum);
    }
    if (n > 20) {
        for (int i = 0; i < (1 << (n - 20)); i++) {
            ll sum = 0;
            for (int k = 0; k < (n - 20); k++) if ((1 << k) & i) sum += nums[k + 20];
            if (sum <= x) sums_two.push_back(sum);
        }
    }
    else sums_two.push_back(0);

    sort(sums_one.begin(), sums_one.end());
    sort(sums_two.begin(), sums_two.end());
    c_one.emplace_back(sums_one[0], 1);
    c_two.emplace_back(sums_two[0], 1);

    ll ans = 0;
    for (int i = 1; i < sums_one.size(); i++) {
        if (sums_one[i] != sums_one[i - 1]) c_one.emplace_back(sums_one[i], 1);
        else c_one[c_one.size() - 1].second++;
    }
    for (int i = 1; i < sums_two.size(); i++) {
        if (sums_two[i] != sums_two[i - 1]) c_two.emplace_back(sums_two[i], 1);
        else c_two[c_two.size() - 1].second++;
    }

    int one_size = (int) c_one.size(), two_size = (int) c_two.size();
    int left = 0, right = two_size - 1;

    while (left < one_size && right >= 0) {
        if (c_one[left].first + c_two[right].first == x) {
            ans += c_one[left].second * c_two[right].second;
            left++, right--;
        }
        else if (c_one[left].first + c_two[right].first < x) left++;
        else right--;
    }

    cout << ans << endl;
}