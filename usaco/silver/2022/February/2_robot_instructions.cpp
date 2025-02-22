//
// Created by TheUnicat on 2024-12-11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
ll x, y;
vector<vector<pair<ll, ll>>> s_one, s_two;
vector<pair<ll, ll>> instructs;

int main() {
    cin >> n >> x >> y;
    int half = n / 2;
    s_one.resize(min(half, n) + 1);
    s_two.resize(max(0, n - half) + 1);
    instructs.resize(n);
    for (ll i = 0; i < n; i++) cin >> instructs[i].first >> instructs[i].second;

    for (ll i = 0; i < (1 << half); i++) {
        ll sum_x = 0, sum_y = 0;
        ll t_instructs = 0;
        for (ll j = 0; j < min(half, n); j++) if ((1 << j) & i) {
            sum_x += instructs[j].first, sum_y += instructs[j].second;
            t_instructs++;
        }
        s_one[t_instructs].emplace_back(sum_x, sum_y);
    }
    for (ll i = 0; i < (1 << (n - half)); i++) {
        ll sum_x = 0, sum_y = 0;
        ll t_instructs = 0;
        for (ll j = 0; j < n - half; j++) if ((1 << j) & i) {
            sum_x += instructs[j + half].first, sum_y += instructs[j + half].second;
            t_instructs++;
        }
        s_two[t_instructs].emplace_back(sum_x, sum_y);
    }
    if (n - half <= 0) s_two[0].emplace_back(0, 0);

    for (ll i = 0; i < min(half, n) + 1; i++) sort(s_one[i].begin(), s_one[i].end());
    for (ll i = 0; i < max(n - half, 0) + 1; i++) sort(s_two[i].begin(), s_two[i].end());

    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int j = 0; j <= i; j++) {
            if (j >= s_one.size() || (i - j) >= s_two.size()) continue;
            int one = j, two = i - j;
            ll one_len = (ll) s_one[one].size(), two_len = (ll) s_two[two].size();
            ll left = 0, right = two_len - 1;
            while (left < one_len && right >= 0) {
                if (s_one[one][left].first + s_two[two][right].first == x) {
                    if (s_one[one][left].second + s_two[two][right].second == y) {
                        ll one_size = 1, two_size = 1;
                        while (left < one_len - 1 && s_one[one][left + 1] == s_one[one][left]) left++, one_size++;
                        while (right > 0 && s_two[two][right - 1] == s_two[two][right]) right--, two_size++;
                        ans += one_size * two_size;
                        left++, right--;
                    }
                    else if (s_one[one][left].second + s_two[two][right].second < y) left++;
                    else right--;
                }
                else if (s_one[one][left].first + s_two[two][right].first < x) left++;
                else right--;
            }
        }

        cout << ans << endl;
    }
}