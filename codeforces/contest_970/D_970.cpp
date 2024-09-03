//
// Created by TheUnicat on 2024-09-03.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;
ll x, y;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll count_n = 0;
        int n;
        cin >> n;
        vector<bool> top_row(n + 1, false);
        vector<bool> bottom_row(n + 1, false);
        int n_top = 0;
        int n_bottom = 0;

        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            if (y == 0) {
                bottom_row[x] = true;
                n_bottom++;
            }
            else {
                top_row[x] = true;
                n_top++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (!top_row[j]) continue;
            if (bottom_row[j]) {
                count_n += n_top - 1;
                count_n += n_bottom - 1;
            }
            if (j == 0 || j == n - 1) continue;
            if (bottom_row[j - 1] && bottom_row[j + 1]) {
                count_n++;
            }
        }

        for (int j = 1; j < n - 1; j++) {
            if (!bottom_row[j]) continue;
            if (top_row[j - 1] && top_row[j + 1]) count_n++;
        }

        cout << count_n << endl;
    }
}

