//
// Created by TheUnicat on 2024-09-08.
//

#include <iostream>
#include <string>
using namespace std;

string one, two;
int len_one, len_two;
int dp[5001][5001];

int main() {
    cin >> one >> two;
    len_one = (int) one.length();
    len_two = (int) two.length();

    for (int i = 0; i <= len_one; i++) {
        for (int j = 0; j <= len_two; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + 1;
                continue;
            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + 1;
                continue;
            }

            if (one[i - 1] == two[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j - 1] + 1;

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    cout << dp[len_one][len_two];
}