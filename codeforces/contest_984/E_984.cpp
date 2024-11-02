//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, q;

int main() {
    cin >> n >> k >> q;
    vector<vector<int>> water(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> water[j][i];
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            water[i][j] = water[i][j] | water[i][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        int rightmost = n - 1, leftmost = 0;
        for (int j = 0; j < m; j++) {
            int r, c;
            char sign;
            cin >> r >> sign >> c;
            r--;
            if (sign == '>') {
                auto it = upper_bound(water[r].begin(), water[r].end(), c);
                leftmost = max(leftmost, (int) distance(water[r].begin(), it));
            }
            else {
                auto it = lower_bound(water[r].begin(), water[r].end(), c);
                it--;
                rightmost = min(rightmost, (int) distance(water[r].begin(), it));
            }
        }

        if (rightmost >= leftmost) cout << leftmost + 1;
        else cout << -1;
        cout << endl;
    }
}