//
// Created by TheUnicat on 2025-02-06.
//

#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<__int128> hash_prefixes;
vector<__int128> powers;
string n, h;
__int128 n_len, h_len, a = 3984902383;

__int128 mod_n = (((__int128) 1) << 61) - 1, p_hash = 0;

__int128 expo(__int128 num, __int128 pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num;
    if (pow & 1) return num * expo(num, pow - 1) % mod_n;
    return expo(num * num % mod_n, pow / 2) % mod_n;
}

int main() {
    a = a * a;
    cin >> n >> h;
    n_len = (int) n.length(), h_len = (int) h.length();
    hash_prefixes.resize(h_len + 1, 0);
    powers.resize(h_len);
    __int128 curr_hash = 0, ans = 0, pow = 1;

    for (int i = 0; i < h_len; i++) {
        powers[i] = pow;
        pow *= a;
        pow %= mod_n;
    }
    for (int i = 0; i < h_len; i++) {
        curr_hash += h[i] * powers[i];
        curr_hash %= mod_n;
        hash_prefixes[i + 1] = curr_hash;
    }

    set<__int128> seen;
    map<char, int> freq, curr_freq;
    for (char character : n) freq[character]++;
    for (int i = 0; i < n_len; i++) {
        curr_freq[h[i]]++;
    }
    bool match = true;
    for (int i = 0; i < 26; i++) {
        if (curr_freq[(char) (i + 97)] != freq[(char) (i + 97)]) match = false;
    }
    if (match) {
        ans++;
        seen.insert(hash_prefixes[n_len]);
    }

    for (__int128 i = n_len; i < h_len; i++) {
        curr_hash = ((hash_prefixes[i + 1] - hash_prefixes[i - n_len + 1] + mod_n) % mod_n * expo(powers[i - n_len + 1], mod_n - 2)) % mod_n;
        curr_freq[h[i - n_len]]--;
        curr_freq[h[i]]++;
        match = true;
        for (int j = 0; j < 26; j++) {
            if (curr_freq[(char) (j + 97)] != freq[(char) (j + 97)]) match = false;
        }

        if (match && seen.find(curr_hash) == seen.end()) {
            ans++;
            seen.insert(curr_hash);
        }
    }

    cout << (long long) ans << endl;
}