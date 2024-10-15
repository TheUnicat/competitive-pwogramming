//
// Created by TheUnicat on 2024-10-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

ll t, n, k;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        vector<int> cards(n);
        unordered_map<int, int> freq;
        for (int j = 0; j < n; j++) {
            cin >> cards[j];
            freq[cards[j]]++;
        }

        sort(cards.begin(), cards.end());

        ll max_taken = 0;
        ll left = 0;
        unordered_map<ll, ll> counts;
        ll distinct_numbers = 0;

        for (ll right = 0; right < n; right++) {
            if (counts[cards[right]] == 0) {
                distinct_numbers++;
            }
            counts[cards[right]]++;

            while (right > left && cards[right] - cards[right - 1] > 1) {
                counts[cards[left]]--;
                if (counts[cards[left]] == 0) {
                    distinct_numbers--;
                }
                left++;
            }

            while (distinct_numbers > k) {
                counts[cards[left]]--;
                if (counts[cards[left]] == 0) {
                    distinct_numbers--;
                }
                left++;
            }

            max_taken = max(max_taken, right - left + 1);
        }
        cout << max_taken << endl;
    }
}