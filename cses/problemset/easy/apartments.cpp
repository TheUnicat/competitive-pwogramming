//
// Created by TheUnicat on 2025-03-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll n, m, k;
vector<ll> apartments, applicants;

int main() {
    cin >> n >> m >> k;
    apartments.resize(m);
    applicants.resize(n);
    for (int i = 0; i < n; i++) cin >> applicants[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];
    sort(apartments.begin(), apartments.end());
    sort(applicants.begin(), applicants.end());
    ll curr_apartment = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (curr_apartment == m) break;
        while (applicants[i] - apartments[curr_apartment] > k) {
            curr_apartment++;
            if (curr_apartment == m) break;
        }
        if (curr_apartment == m) break;
        if (abs(applicants[i] - apartments[curr_apartment]) <= k) {
            curr_apartment++;
            ans++;
            if (curr_apartment == m) break;
        }
    }

    cout << ans << endl;
}