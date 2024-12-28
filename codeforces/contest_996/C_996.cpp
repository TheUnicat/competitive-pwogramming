//
// Created by TheUnicat on 2024-12-24.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

ll t, n;

int main() {
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> n;
        vector<ll> nums(n);
        set<ll> solutions;
        ll max_pos = n;
        ll max_val = 0;
        for (ll j = 0; j < n; j++) {
            cin >> nums[j];
            if (nums[j] != 1 && nums[j] != -1) {
                max_pos = j;
                max_val = nums[j];
            }
        }


        ll prefix_min = 0, prefix_max = 0, suffix_min = 0, suffix_max = 0, abs_prefix_max = 0, abs_prefix_min = 0, abs_suffix_max = 0, abs_suffix_min = 0;
        ll sum = 0, min_sum = 0, max_sum = 0;
        for (ll j = max_pos - 1; j >= 0; j--) {
            sum += nums[j];
            abs_prefix_max = max(abs_prefix_max, sum - min_sum);
            min_sum = min(min_sum, sum);
            abs_prefix_min = min(abs_prefix_min, sum - max_sum);
            max_sum = max(max_sum, sum);
            prefix_max = max(prefix_max, sum);
            prefix_min = min(prefix_min, sum);
        }

        sum = 0, max_sum = 0, min_sum = 0;
        multiset<ll> suffix_sums;
        suffix_sums.insert(0);
        for (ll j = max_pos + 1; j < n; j++) {
            sum += nums[j];
            abs_suffix_max = max(abs_suffix_max, sum - min_sum);
            min_sum = min(min_sum, sum);
            abs_suffix_min = min(abs_suffix_min, sum - max_sum);
            max_sum = max(max_sum, sum);
            suffix_max = max(suffix_max, sum);
            suffix_min = min(suffix_min, sum);
        }

        ll range_min = prefix_min + suffix_min;
        ll range_max = prefix_max + suffix_max;
        for (ll j = min(abs_prefix_min, abs_suffix_min); j <= max(abs_prefix_max, abs_suffix_max); j++) solutions.insert(j);
        for (ll j = range_min; j <= range_max; j++) solutions.insert(j + max_val);

        sum = 0;
        for (ll j = 0; j < max_pos; j++) {
            sum += nums[j];
            solutions.insert(sum);
        }
        sum = 0;
        for (ll j = n - 1; j > max_pos; j--) {
            sum += nums[j];
            solutions.insert(sum);
        }
        solutions.insert(0);
        solutions.insert(max_val);

        auto it = solutions.begin();
        cout << solutions.size() << endl;
        while (it != solutions.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }

}