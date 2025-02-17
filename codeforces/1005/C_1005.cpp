//
// Created by TheUnicat on 2025-02-16.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll ans = 0;
        cin >> n;
        vector<ll> nums(n);
        for (int j = 0; j < n; j++) cin >> nums[j];

        ll pos_sum = 0, neg_sum = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] > 0) {
                pos_sum += nums[j];
                if (pos_sum >= neg_sum) {
                    ans += pos_sum;
                    pos_sum = 0, neg_sum = 0;
                }
            }
            else neg_sum += -nums[j];
        }
        ans += neg_sum;
        cout << ans << endl;
    }
}