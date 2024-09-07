//
// Created by TheUnicat on 2024-09-07.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int mod_n = 1000000007;
vector<vector<char> > grid(1000, vector<char>(1000));
vector<vector<int> > dp(1000, vector<int>(1000, 0));

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            grid[i][j] = line[j];
        }
    }

    dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == '*') continue;
            if (j != 0) {
                dp[i][j - 1] += dp[i][j];
                dp[i][j - 1] %= mod_n;
            }
            if (i != 0) {
                dp[i - 1][j] += dp[i][j];
                dp[i - 1][j] %= mod_n;
            }
        }
    }

    if (grid[0][0] == '*') dp[0][0] = 0;

    cout << dp[0][0];
}