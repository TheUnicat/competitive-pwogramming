//
// Created by TheUnicat on 2024-08-27.
//

#include <iostream>
using namespace std;

int num;

int main() {
    cin >> num;
    int dp[num + 1];
    fill(dp, dp + num + 1, 1000000);
    dp[0] = 0;

    for (int i = 1; i <= num; i++) {
        int mod_n = 10;
        while (mod_n / 10 <= i) {
            int digit = (i % mod_n);
            digit /= mod_n / 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            mod_n *= 10;
        }
    }

    cout << dp[num];
}