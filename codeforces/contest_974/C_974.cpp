//
// Created by TheUnicat on 2024-09-21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<ll> people(n);
        ll sum = 0;
        ll max_wealth = 0;
        for (int j = 0; j < n; j++) {
            cin >> people[j];
            sum += people[j];
            max_wealth = max(max_wealth, people[j]);
        }
        sort(people.begin(), people.end());
        int median_index = n / 2;

        if (n < 3) {
            cout << -1 << endl;
            continue;
        }

        ll min_average_wealth = people[median_index] * 2;
        ll min_total_wealth = min_average_wealth * n;

        cout << max(min_total_wealth - sum + 1, (ll) 0) << endl;
    }
}