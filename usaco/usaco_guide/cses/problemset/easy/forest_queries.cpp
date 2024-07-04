//
// Created by TheUnicat on 2024-07-03.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > forest_prefix_sums;
    vector<vector<bool> > forest;
    for (int i = 0; i < n; i++) {
        vector<int> row_prefix_sums(n);
        vector<bool> forest_row(n);
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            int num;
            char in;
            cin >> in;
            num = in == '*' ? 1 : 0;
            forest_row[j] = in == '*' ? true : false;
            row_sum += num;
            if (i > 0) {
                row_prefix_sums[j] = row_sum + forest_prefix_sums[i - 1][j];
            }
            else {
                row_prefix_sums[j] = row_sum;
            }
        }
        forest.push_back(forest_row);
        forest_prefix_sums.push_back(row_prefix_sums);
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

