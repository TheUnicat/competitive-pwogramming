//
// Created by TheUnicat on 2024-08-28.
//

#include <iostream>
using namespace std;
using ll = long long;

ll n, k;
ll total_cost = 0;
ll prev_day, day;

int main() {
    cin >> n >> k;
    total_cost += k + 1;
    cin >> prev_day;
    for (int i = 0; i < n - 1; i++) {
        cin >> day;
        total_cost += min(k + 1, (day - prev_day));
        prev_day = day;
    }

    cout << total_cost;
}