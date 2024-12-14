//
// Created by TheUnicat on 2024-12-13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<ll> a_freq, b_freq;
vector<ll> a_start, b_end;

int main() {
    cin >> n >> m;
    a_freq.resize(m + 1, 0);
    b_freq.resize(m + 1, 0);
    a_start.resize(2 * m + 1, 0);
    b_end.resize(2 * m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a_freq[a]++;
        b_freq[b]++;
    }
    for (int i = 0; i <= 2 * m + 1; i++) {
        for (int j = 0; j <= min(i, m); j++) {
            if (i - j > m) continue;
            a_start[i] += a_freq[j] * a_freq[i - j];
            b_end[i] += b_freq[j] * b_freq[i - j];
        }
    }
    ll ans = 0;
    for (int k = 0; k <= 2 * m; k++) {
        ans += a_start[k];
        cout << ans << endl;
        ans -= b_end[k];
    }
}