//
// Created by TheUnicat on 2024-07-03.
//

#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int forest_prefix_sums[n][n];
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            int num;
            char in;
            cin >> in;
            num = in == '*' ? 1 : 0;
            row_sum += num;
            if (i > 0) {
                forest_prefix_sums[i][j] = row_sum + forest_prefix_sums[i - 1][j];
            }
            else {
                forest_prefix_sums[i][j] = row_sum;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = forest_prefix_sums[c - 1][d - 1];
        if (a - 1 > 0) {
            sum -= forest_prefix_sums[a - 2][d - 1];
        }
        if (b - 1 > 0) {
            sum -= forest_prefix_sums[c - 1][b - 2];
        }

        if (a - 1 > 0 && b - 1 > 0) {
            sum += forest_prefix_sums[a - 2 ][b - 2];
        }
        cout << sum << endl;
    }
}

