//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int j = 0; j < t; j++) {
        ll l, r, i, k;
        ll xor_sum = 0;
        cin >> l >> r >> i >> k;
        for (int m = 0; m < 62; m++) {
            ll mod_val = 1 << i;
            ll val = 1 << m;
            ll new_right = r - (r % mod_val);
            if (r & mod_val) new_right = r;
            ll new_left = l + mod_val - (l % mod_val);
            if (l & mod_val) new_left = l;

            ll original_count = (new_right - new_left) / val + 1;

        }
    }
}