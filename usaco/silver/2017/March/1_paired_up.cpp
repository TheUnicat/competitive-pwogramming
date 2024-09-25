//
// Created by TheUnicat on 2024-09-24.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int max_time = 0;
vector<pair<int, int>> cows;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cows.emplace_back(y, x);
    }
    sort(cows.begin(), cows.end());
    int one = 0, two = n - 1;
    while (one <= two) {
        max_time = max(max_time, cows[one].first + cows[two].first);
        if (one == two) break;

        int n_cows_processed = min(cows[one].second, cows[two].second);
        cows[one].second -= n_cows_processed;
        cows[two].second -= n_cows_processed;
        if (cows[one].second <= 0) one++;
        if (cows[two].second <= 0) two--;
    }

    cout << max_time;
}