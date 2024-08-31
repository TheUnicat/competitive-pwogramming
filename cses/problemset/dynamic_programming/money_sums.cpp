//
// Created by TheUnicat on 2024-08-27.
//

#include <iostream>
#include <vector>
using namespace std;

int coin_sum = 0;
int n_coins;

int main() {
    cin >> n_coins;
    int coins[n_coins];
    for (int i = 0; i < n_coins; i++) {
        cin >> coins[i];
        coin_sum += coins[i];
    }

    bool dp[coin_sum + 1];
    fill(dp, dp + coin_sum + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        for (int i = coin_sum - coin; i >= 0; i--) {
            if (dp[i]) dp[i + coin] = true;
        }
    }

    int formable = 0;
    for (int i = 1; i <= coin_sum; i++) if (dp[i]) formable++;
    cout << formable << endl;
    for (int i = 1; i <= coin_sum; i++) if (dp[i]) cout << i << " ";
}