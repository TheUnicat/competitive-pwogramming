//
// Created by TheUnicat on 2024-12-02.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll cost = 0;
        int n;
        cin >> n;
        int max_other_cell = -1e9;
        vector<pair<int, int>> grid(n);
        for (int j = 0; j < n; j++) cin >> grid[j].first;
        for (int j = 0; j < n; j++) cin >> grid[j].second;
        for (int j = 0; j < n; j++) {
            int a = grid[j].first, b = grid[j].second;
            if (a > b) {
                max_other_cell = max(max_other_cell, b);
                cost += a;
            }
            else {
                max_other_cell = max(max_other_cell, a);
                cost += b;
            }
        }

        cost += max_other_cell;
        cout << cost << endl;
    }
}