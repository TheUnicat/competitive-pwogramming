//
// Created by TheUnicat on 2024-09-03.
//

#include <iostream>
using namespace std;
using ll = long long;

int t;

ll diff(ll n, ll k, ll i) {
    ll first_sum = (i - k + 1) * (k + i) / 2;
    ll second_sum = (n + k - i - 1) * (i + n + k) / 2;
    return abs(second_sum - first_sum);
}

ll solve(int n, int k) {
    int min_i = k;
    int max_i = n + k - 2;
    ll lowest_sol = 9100000000000000000;

    while (max_i >= min_i) {
        ll mid = min_i + (max_i - min_i) / 2;
        ll first_diff = diff(n, k, mid);
        ll second_diff = diff(n, k, mid + 1);
        if (first_diff == second_diff) return first_diff;
        if (first_diff < second_diff) {
            lowest_sol = min(first_diff, lowest_sol);
            max_i = mid - 1;
        }
        else {
            lowest_sol = min(lowest_sol, second_diff);
            min_i = mid + 1;
        }
    }

    return lowest_sol;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
