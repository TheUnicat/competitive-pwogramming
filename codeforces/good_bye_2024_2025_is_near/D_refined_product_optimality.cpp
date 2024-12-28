//
// Created by TheUnicat on 2024-12-28.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll t, n, q;
int mod_n = 998244353;

ll pow(ll num, ll exp) {
    if (exp == 1) return num;
    if (exp & 1) {
        return (num * pow(num, exp - 1)) % mod_n;
    }
    return pow((num * num) % mod_n, exp / 2) % mod_n;
}

ll mod_inv(ll num) {
    return pow(num, mod_n - 2) % mod_n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        ll product = 1;
        cin >> n >> q;
        vector<ll> one(n), two(n);
        for (int j = 0; j < n; j++) cin >> one[j];
        for (int j = 0; j < n; j++) cin >> two[j];
        vector<ll> orig_one = one, orig_two = two;
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        for (int j = 0; j < n; j++) {
            product *= min(one[j], two[j]);
            product %= mod_n;
        }
        cout << product << " ";
        for (int j = 0; j < q; j++) {
            int list, idx;
            cin >> list >> idx;
            idx--;
            if (list == 1) {
                int changed_idx = distance(one.begin(), upper_bound(one.begin(), one.end(), orig_one[idx])) - 1;
                one[changed_idx]++;
                orig_one[idx]++;
                if (one[changed_idx] <= two[changed_idx]) {
                    product = product * mod_inv(one[changed_idx] - 1) % mod_n * one[changed_idx] % mod_n;
                }
                cout << product << " ";
            }
            else {
                int changed_idx = distance(two.begin(), upper_bound(two.begin(), two.end(), orig_two[idx])) - 1;
                two[changed_idx]++;
                orig_two[idx]++;
                if (two[changed_idx] <= one[changed_idx]) {
                    product = product * mod_inv(two[changed_idx] - 1) % mod_n * two[changed_idx] % mod_n;
                }
                cout << product << " ";
            }
        }
        cout << endl;
    }
}