//
// Created by TheUnicat on 2025-02-09.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

string input;
vector<ll> hash_prefixes, powers;
ll n, a = 400, mod = 1e9 + 7, curr_power = 1;

ll expo(ll num, ll pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num;
    if (pow & 1) return num * expo(num, pow - 1) % mod;
    return expo(num * num % mod, pow / 2) % mod;
}

ll get_hash(ll l, ll r) {
    return (hash_prefixes[r] - (hash_prefixes[l] * powers[r - l] % mod) + mod) % mod;
}

int main() {
    cin >> input;
    n = (ll) input.length();
    hash_prefixes.resize(n + 1), powers.resize(n);
    hash_prefixes[0] = 0;
    for (int i = 0; i < n; i++) {
        powers[i] = curr_power;
        curr_power *= a;
        curr_power %= mod;
        hash_prefixes[i + 1] = (hash_prefixes[i] * a + input[i]) % mod;
    }

    for (int i = 1; i <= n; i++) {
        bool match = true;

        int j = i;
        ll correct = hash_prefixes[i];
        while (j <= n) {
            int r = j, l = j - i;
            if (get_hash(l, r) != correct) {
                match = false;
                break;
            }
            j += i;
        }
        if (match) {
            if (n % i == 0) cout << i << " ";
            else {
                ll correct_suffix = hash_prefixes[n % i];
                ll l = n  - (n % i);
                if (get_hash(l, n) != correct_suffix) continue;
                cout << i << " ";
            }
        }
    }
}