//
// Created by TheUnicat on 2024-09-14.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
using ll = long long;

int t, n, l;
map<int, char> int_to_char;

int main() {
    cin >> t;
    int_to_char[0] = 'n';
    int_to_char[1] = 'a';
    int_to_char[2] = 'r';
    int_to_char[3] = 'e';
    int_to_char[4] = 'k';

    for (int i = 0; i < t; i++) {
        cin >> n >> l;
        vector<vector<ll>> dp(n + 1, vector<ll>(5, (ll) -10e10));
        vector<string> strings(n);
        for (int j = 0; j < n; j++) {
            cin >> strings[j];
        }
        dp[0][0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 5; k++) {
                if (dp[j - 1][k] == (ll) -10e10) continue;
                dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                int curr_int = k;
                int curr_score = 0;
                for (char character : strings[j - 1]) {
                    if (character == int_to_char[curr_int]) {
                        curr_int++;
                        curr_int %= 5;
                        if (curr_int == 0) curr_score += 5;
                    }
                    else {
                        if (character == 'n' || character == 'a' || character == 'r' || character == 'e' || character == 'k') {
                            curr_score--;
                        }
                    }
                }
                dp[j][curr_int] = max(dp[j][curr_int], dp[j - 1][curr_int]);
                dp[j][curr_int] = max(dp[j][curr_int], dp[j - 1][k] + curr_score);
            }
        }

        ll max_score = dp[n][0];
        dp[n][1] -= 1;
        dp[n][2] -= 2;
        dp[n][3] -= 3;
        dp[n][4] -= 4;
        max_score = max(max_score, dp[n][1]);
        max_score = max(max_score, dp[n][2]);
        max_score = max(max_score, dp[n][3]);
        max_score = max(max_score, dp[n][4]);

        cout << max_score << endl;
    }
}