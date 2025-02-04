//
// Created by TheUnicat on 2025-01-30.
//

#include <iostream>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

ll exponentiate(ll num, ll pow, ll modulus) {
    if (pow == 0) return 1;
    if (pow == 1) return num;
    if (pow & 1) return num * exponentiate(num, pow - 1, modulus) % modulus;
    return exponentiate(num * num % modulus, pow / 2, modulus) % modulus;
}

ll solve(ll a, ll b, ll c) {
    ll bc = exponentiate(b, c, mod - 1);
    return exponentiate(a, bc, mod);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
}

