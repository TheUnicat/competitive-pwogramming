//
// Created by TheUnicat on 2025-02-16.
//

#include <iostream>
#include <vector>
using namespace std;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> nums(n);
        vector<int> seen(n + 1, 0);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
            seen[nums[j]]++;
        }
        int ans_l = -1, ans_r = -1;
        int l = 0;
        for (int j = 0; j < n; j++) {
            if (seen[nums[j]] > 1) {
                l = j + 1;
                continue;
            }
            if (j - l >= ans_r - ans_l) {
                ans_l = l, ans_r = j;
            }
        }
        if (ans_l == -1) cout << 0 << endl;
        else {
            cout << ans_l + 1 << " " << ans_r + 1 << endl;
        }
    }
}