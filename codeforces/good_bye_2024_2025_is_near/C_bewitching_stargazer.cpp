//
// Created by TheUnicat on 2024-12-28.
//

#include <iostream>
using namespace std;
using ll = long long;

ll t, n, k;

pair<ll, ll> solve(ll input) {
    if (input < k) return {0, 0};
    if (input == 1) return {1, 1};
    auto half = solve(input / 2);
    if (input & 1) return {2 * half.first + half.second * (input / 2 + 1) + input / 2 + 1, half.second * 2 + 1};
    return {2 * half.first + half.second * (input / 2), half.second * 2};
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        cout << solve(n).first << endl;
    }
}