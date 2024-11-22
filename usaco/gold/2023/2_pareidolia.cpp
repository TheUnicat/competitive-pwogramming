//
// Created by TheUnicat on 2024-11-21.
//

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
using ll = long long;

string test;
string bessie = "bessie";
vector<ll> cost(200000);
vector<vector<ll>> dp(200001, vector<ll>(6, LONG_LONG_MAX));
vector<vector<ll>> n_occurences(200001, vector<ll>(6, 0));
ll str_len;

int main() {
    dp[0][0] = 0;
    cin >> test;
    str_len = (ll) test.size();
    for (ll i = 0; i < str_len; i++) cin >> cost[i];

    for (ll i = 0; i < str_len; i++) {
        for (ll j = 0; j < 6; j++) {
            if (dp[i][j] == LONG_LONG_MAX) continue;

            if (dp[i + 1][j] >= dp[i][j] + cost[i] && n_occurences[i][j] >= n_occurences[i + 1][j] || n_occurences[i][j] > n_occurences[i + 1][j]) {
                dp[i + 1][j] = dp[i][j] + cost[i];
                n_occurences[i + 1][j] = n_occurences[i][j];
            }
            if (test[i] == bessie[j]) {
                if (dp[i][j] <= dp[i + 1][(j + 1) % 6] && n_occurences[i][j] + (j == 5) >= n_occurences[i + 1][(j + 1) % 6] || n_occurences[i][j] + (j == 5) > n_occurences[i + 1][(j + 1) % 6]) {
                    dp[i + 1][(j + 1) % 6] = dp[i][j];
                    if (j == 5) n_occurences[i + 1][0] = n_occurences[i][j] + 1;
                    else n_occurences[i + 1][j + 1] = n_occurences[i][j];
                }
            }
            else {
                if (test[i] == 'b') {
                    if (dp[i + 1][1] >= dp[i][j] && n_occurences[i][j] >= n_occurences[i + 1][1] || n_occurences[i][j] > n_occurences[i + 1][1]) {
                        dp[i + 1][1] = dp[i][j];
                        n_occurences[i + 1][1] = n_occurences[i][j];
                    }
                }
                else {
                    if (dp[i + 1][0] >= dp[i][j] && n_occurences[i][j] >= n_occurences[i + 1][0] || n_occurences[i][j] > n_occurences[i + 1][0]) {
                        dp[i + 1][0] = dp[i][j];
                        n_occurences[i + 1][0] = n_occurences[i][j];
                    }
                }
            }

        }
    }
    ll min_cost = LONG_LONG_MAX, max_occurences = 0;
    for (ll i = 0; i < 6; i++) {
        if (n_occurences[str_len][i] > max_occurences) {
            min_cost = dp[str_len][i];
            max_occurences = n_occurences[str_len][i];
        }
        else if (n_occurences[str_len][i] == max_occurences) {
            min_cost = min(min_cost, dp[str_len][i]);
        }
    }

    cout << max_occurences << endl << min_cost << endl;
}
