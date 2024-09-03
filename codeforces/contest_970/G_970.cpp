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
        vector<ll> prefix_sums(n + 1);
        prefix_sums[0] = 0;
        for (int j = 0; j < n; j++) {
            cin >> prefix_sums[j + 1];
            prefix_sums[j + 1] += prefix_sums[j];
        }

        for (int j = 0; j < q; j++) {
            ll final_sum = 0;
            int l, r;
            cin >> l >> r;
            int begin_pos = l % n;
            int begin_next_full_cycle = l / n;
            if (l % n != 0) begin_next_full_cycle++;

            int end_pos = r % n;
            int end_past_full_cycle = r / n;

            int full_cycles = max(0, (end_past_full_cycle - begin_next_full_cycle));
            final_sum += prefix_sums[n] * full_cycles;

            int begin_shift = (l - 1) / n;
            int end_shift = (r - 1) / n;

            int shifted_begin = begin_shift + begin_pos;
            int shifted_end = end_shift + end_pos;
            if (end_shift == begin_shift) {
                if (shifted_end <= n) {
                    final_sum += (prefix_sums[shifted_end] - prefix_sums[shifted_begin - 1]);
                }
                else if (shifted_begin <= n) {
                    final_sum += prefix_sums[n] - prefix_sums[shifted_begin - 1];
                    final_sum += prefix_sums[shifted_end % n];
                }
                else {
                    final_sum += prefix_sums[shifted_end % n] - prefix_sums[shifted_begin % n - 1];
                }
            }
            else {
                final_sum += prefix_sums[n] - prefix_sums[shifted_begin % n - 1];
                final_sum += prefix_sums[shifted_end];
            }
        }
    }
}