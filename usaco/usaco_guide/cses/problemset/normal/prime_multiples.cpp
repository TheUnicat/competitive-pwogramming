//
// Created by TheUnicat on 2024-08-12.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll n, k;
vector<ll> primes;
ll sum = 0;
ll set_num = 1;

int main() {
    cin >> n >> k;
    primes.resize(k);
    for (int i = 0; i < k; i++) cin >> primes[i];

    while (set_num < (1 << k)) {
        ll product = 1;
        bool overflow = false;
        for (int i = 0; i < k; i++) {
            if (set_num & (1 << i)) {
                if (n / primes[i] < product) {
                    overflow = true;
                    break;
                }
                product *= primes[i];
            }
        }

        if (overflow) {
            set_num++;
            continue;
        }

        if (__builtin_popcount(set_num) & 1) sum += n / product;
        else sum -= n / product;

        set_num++;
    }

    cout << sum;
}
