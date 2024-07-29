//
// Created by TheUnicat on 2024-07-29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll n, k;

int main() {
    cin >> n >> k;
    vector<ll> numbers(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    vector<ll> real_numbers(numbers.begin() + (n / 2), numbers.end());


    int right_index = 0;
    ll current_median = real_numbers[0];

    while (k > 0) {
        if (right_index == real_numbers.size() - 1) {
            cout << current_median + k / (right_index + 1);
            return 0;
        }
        else {
            ll next_value = real_numbers[right_index + 1];
            if (next_value == current_median) {
                right_index++;
                continue;
            }
            if ((next_value - current_median) * (right_index + 1) > k) {
                cout << current_median + k / (right_index + 1);
                return 0;
            }
            k -= (next_value - current_median) * (right_index + 1);
            current_median = next_value;
            right_index++;
        }
    }

    cout << current_median;
}