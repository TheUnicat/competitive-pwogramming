//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;

ll xor_prefix(ll n) {
    if (n % 4 == 0) {
        return n;
    }
    if (n % 4 == 1) {
        return 1;
    }
    if (n % 4 == 2) {
        return n + 1;
    }

    return 0;
}

ll xor_range(ll n, ll m) {
    return xor_prefix(n - 1) ^ xor_prefix(m);
}

ll two_exp(ll num) {
    return 1 << num;
}

int main() {
    cin >> t;
    for (int j = 0; j < t; j++) {
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        ll curr_xor = xor_range(l, r);
        ll min_h = (l - k) / two_exp(i);
        if (k + min_h * two_exp(i) < l) min_h++;
        ll max_h  = (r - k) / two_exp(i);
        bool works = (((k + min_h * two_exp(i)) <= r && (k + min_h * two_exp(i)) >= l)) || (((k + max_h * two_exp(i)) <= r && (k + max_h * two_exp(i)) >= l));
        ll h_xor = xor_range(min_h, max_h);
        h_xor <<= i;
        if ((max_h - min_h) % 2 == 0 && works) h_xor ^= k;

        cout << (h_xor ^ curr_xor) << endl;
    }
}
