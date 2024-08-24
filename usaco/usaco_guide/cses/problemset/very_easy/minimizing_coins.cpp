//
// Created by TheUnicat on 2024-08-24.
//

#include <iostream>
#include <vector>
using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> min_coins(x + 1, x + 1);
    min_coins[0] = 0;
    for (int i = 0; i < n; i++) cin >> coins[i];

    for (int i = 0; i < x; i++) {
        if (min_coins[i] == x + 1) continue;
        for (int coin : coins) {
            if (i + coin <= x) min_coins[i + coin] = min(min_coins[i + coin], 1 + min_coins[i]);
        }
    }

    if (min_coins[x] == x + 1) cout << -1;
    else cout << min_coins[x];
}