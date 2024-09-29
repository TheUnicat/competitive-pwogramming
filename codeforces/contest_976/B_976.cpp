//
// Created by TheUnicat on 2024-09-29.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int t;
ll n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        ll max_n = 2 * n;
        ll min = n;
        ll min_solution = LLONG_MAX;

        while (max_n >= min) {
            ll mid = min + (max_n - min) / 2;
            ll sol = mid - (ll) sqrt((long double) mid);
            if (sol > n) max_n = mid - 1;
            else if (sol == n) {
                min_solution = mid;
                max_n = mid - 1;
            }
            else min = mid + 1;
        }
        cout << min_solution << endl;
    }
}

