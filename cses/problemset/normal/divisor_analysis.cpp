//
// Created by TheUnicat on 2025-02-03.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;
int n;
ll num = 1, sum = 1, product = 1, num_other_mod = 1;

ll expo(ll val, ll pow) {
    if (pow == 0) return 1;
    if (pow == 1) return val;
    if (pow & 1) return val * expo(val, pow - 1) % mod;
    return expo(val * val % mod, pow / 2) % mod;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, k;
        cin >> x >> k;

        num *= k + 1;
        num %= mod;

        sum = (sum * (expo(x, k + 1) - 1)) % mod * expo(x - 1, mod - 2) % mod;

        product = expo(product, k + 1);
        product *= expo(x, num_other_mod * ((k * (k + 1) / 2) % (mod - 1)) % (mod - 1));
        product %= mod;
        num_other_mod = num_other_mod * (k + 1) % (mod - 1);
    }

    cout << num << " " << sum << " " << product << endl;
}

