//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int t;
int n, k;
int mod_n = 1000000007;
vector<ll> factorials_mod_n(2e5 + 1);

ll power(ll x, ll p, ll m) {
    ll result = 1;

    while (p > 0) {
        if (p % 2 == 1) {
            result = (result * x) % m;
            p--;
        }
        else {
            x = (x * x) % m;
            p /= 2;
        }
    }

    return result;
}

ll inverse(ll num) {
    return power(num, mod_n - 2, mod_n);
}

ll combination(int a, int b) {
    ll product = factorials_mod_n[b] * inverse((factorials_mod_n[a] * factorials_mod_n[b - a]) % mod_n) % mod_n;
    return product;
}


int main() {
    factorials_mod_n[0] = 1;
    for (int i = 1; i <= 2e5; i++) {
        factorials_mod_n[i] = (factorials_mod_n[i - 1] * (i) ) % mod_n;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll sum = 0;
        int ones = 0;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num == 1) ones++;
        }

        for (int j = max(k / 2 + 1, k - n + ones); j <= min(k, ones); j++) {
            ll product = combination(j, ones) % mod_n;
            product *= combination(k - j, n - ones);
            product = product % mod_n;
            sum += product;
            sum = sum % mod_n;
        }

        cout << sum << endl;
    }
}