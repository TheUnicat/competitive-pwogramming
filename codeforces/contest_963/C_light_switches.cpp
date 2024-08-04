//
// Created by TheUnicat on 2024-08-04.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n, k;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        vector<int> test(n);
        for (int j = 0; j < n; j++) cin >> test[j];
        sort(test.begin(), test.end());
        vector<int> remainder;

        for (int j = 0; j < n; j++) {
            int mod = test[j] % (2 * k);
            remainder.push_back(mod);
        }

        pair<int, int> range = make_pair(0, 2 * k);
        bool unsolvable = false;
        for (int value : remainder) {
            if (value < k) {
                range.first = max(range.first, value);
                range.second = min(range.second, value + k);
            }
            else {
                if (range.first <= value - k) {
                    range.second = min(range.second, value - k);
                }
                else if (range.second >= value) {
                    range.first = max(range.first, value);
                }
                else {
                    unsolvable = true;
                    break;
                }
            }
        }

        if (unsolvable || range.second > range.first) {
            cout << -1 << endl;
            continue;
        }

        int adjustment = 0;
        if (test[n - 1] > range.first) {
            adjustment = range.first + (2 * k - test[n - 1]);
        }
        else if (test[n - 1] < range.first) {
            adjustment = range.first - test[n - 1];
        }
        else adjustment = 0;

        cout << test[n - 1] + adjustment << endl;
    }
}