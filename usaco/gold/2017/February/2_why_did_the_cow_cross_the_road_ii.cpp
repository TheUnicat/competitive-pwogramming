//
// Created by TheUnicat on 2024-11-27.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> left_line, right_line;
set<pair<int, int>> edges;

int main() {
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin >> n;
    left_line.resize(n);
    right_line.resize(n);
    for (int i = 0; i < n; i++) cin >> left_line[i].first;
    for (int i = 0; i < n; i++) cin >> right_line[i].first;
    for (int i = 0; i < n; i++) {
        left_line[i].second = i;
        right_line[i].second = i;
    }
    sort(left_line.begin(), left_line.end());
    sort(right_line.begin(), right_line.end());

    for (int i = 0; i < n; i++) {
        for (int j = i - 4; j <= i + 4; j++) {
            if (j < 0 || j >= n) continue;
            edges.emplace(left_line[i].second + 1, right_line[j].second + 1);
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }

            if (edges.find(make_pair(i, j)) != edges.end()) {
                if (dp[i - 1][j - 1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
    }

    cout << dp[n][n] << endl;
}