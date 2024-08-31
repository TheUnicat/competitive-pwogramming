//
// Created by TheUnicat on 2024-07-30.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, k;

bool does_value_work(ll value, const vector<int> &numbers) {
    ll current_sum = 0;
    int n_subdivisions = 1;
    for (int i = 0; i < n; i++) {
        current_sum += numbers[i];
        if (current_sum > value) {
            n_subdivisions++;
            if (n_subdivisions > k) return false;
            current_sum = numbers[i];
            if (current_sum > value) return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> k;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) sum += numbers[i];

    ll min_subdivision_value = sum / n;
    ll max_subdivision_value = sum;
    if (sum % n != 0) min_subdivision_value++;

    ll lowest_max = max_subdivision_value;
    ll prev_value = -1;

    while (max_subdivision_value >= min_subdivision_value) {
        ll mid = min_subdivision_value + (max_subdivision_value - min_subdivision_value) / 2;
        if (mid == prev_value) break;
        prev_value = mid;

        if (does_value_work(mid, numbers)) {
            lowest_max = mid;
            max_subdivision_value = mid - 1;
        }
        else {
            min_subdivision_value = mid + 1;
        }
    }

    cout << lowest_max;
}