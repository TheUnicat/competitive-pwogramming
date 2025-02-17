//
// Created by TheUnicat on 2025-02-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int t, n, q;

int msb(ll num) {
    if (num == 0) return -1;
    ll curr = 1;
    int ans = 0;
    while (curr <= num) {
        curr <<= 1;
        ans++;
    }
    return ans - 1;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> q;
        vector<ll> slimes(n), pref(n + 1, 0);
        vector<vector<int>> msb_pref(31, vector<int>(n, -1));
        for (int j = 0; j < n; j++) cin >> slimes[j];
        reverse(slimes.begin(), slimes.end());
        for (int j = 1; j <= n; j++) pref[j] = slimes[j - 1] ^ pref[j - 1];
        for (int j = n - 1; j >= 0; j--) {
            int msb_curr = msb(slimes[j]);
            if (j != n - 1) for (int k = 0; k <= 30; k++) msb_pref[k][j] = msb_pref[k][j + 1];
            for (int k = msb_curr; k >= 0; k--) msb_pref[k][j] = j;
        }

        for (int j = 0; j < q; j++) {
            ll query;
            cin >> query;
            int curr_msb = msb(query);
            int curr_pos = 0;
            while (true) {
                int new_pos = msb_pref[curr_msb][curr_pos];
                if (new_pos == -1) {
                    cout << n << " ";
                    break;
                }
                ll val = query ^ pref[new_pos];
                if (val < slimes[new_pos]) {
                    cout << new_pos << " ";
                    break;
                }
                curr_pos = new_pos + 1;
                if (curr_pos == n) {
                    cout << n << " ";
                    break;
                }
                curr_msb = msb(val ^ slimes[new_pos]);
                if (curr_msb == -1) {
                    cout << new_pos + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}