//
// Created by TheUnicat on 2025-01-28.
//

#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;
int n;

ll exponentiate(ll num, ll pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num % mod;
    if (pow & 1) return (num * exponentiate(num, pow - 1)) % mod;
    return (exponentiate(num * num % mod, pow / 2)) % mod;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, pow;
        cin >> num >> pow;
        cout << exponentiate(num, pow) << endl;
    }
}