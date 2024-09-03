//
// Created by TheUnicat on 2024-09-03.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        vector<int> values(2 * n);
        vector<ll> prefix_sums(n + 1);
        prefix_sums[0] = 0;
        for (int j = 0; j < n; j++) {
            cin >> prefix_sums[j + 1];
            values[j] = (int) prefix_sums[j + 1];
            values[j + n] = (int) prefix_sums[j + 1];
            prefix_sums[j + 1] += prefix_sums[j];
        }

        for (int j = 0; j < q; j++) {
            ll final_sum = 0;
            int l, r;
            cin >> l >> r;

            int left_shift = (l - 1) / n;
            int right_shift = r / n;

            final_sum += max(0, (right_shift - left_shift - 0)) * prefix_sums[n];
            final_sum += prefix_sums[n] - prefix_sums[l % n - 1];
            final_sum += prefix_sums[right_shift + (r % n)];
            cout << final_sum << endl;
        }
    }
}