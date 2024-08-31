//
// Created by TheUnicat on 2024-08-11.
//

#include <iostream>
using namespace std;
using ll = long long;

int t;

ll solve(ll a, ll b) {
    ll operations = 0;
    ll min_brute_diff = abs(a - b);

    while (a != b) {
        while (a > b) {
            if (a & 1) a++;
            else a /= 2;
            operations++;
        }

        if (operations + b - a < min_brute_diff) {
            min_brute_diff = operations + b - a;
        }

        ll c = a;
        a = b;
        b = c;

        while (a > b) {
            if (operations + a - b < min_brute_diff) {
                min_brute_diff = operations + a - b;
            }
            if (a & 1) {
                a--;
                operations++;
            }
            else {
                a /= 2;
                operations++;
            }
        }

        c = a;
        a = b;
        b = c;
    }

    return min(min_brute_diff, operations);
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        ll sol = solve(a, b);
        cout << sol << endl;
    }
}
