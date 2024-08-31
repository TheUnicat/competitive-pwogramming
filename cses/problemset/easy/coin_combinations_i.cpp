//
// Created by TheUnicat on 2024-08-24.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, x;
int mod_n = 1000000007;
vector<ll> combinations(1000001, 0);
vector<int> coins(100);

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];

    combinations[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) combinations[i] += combinations[i - coins[j]];
        }
        combinations[i] %= mod_n;
    }

    cout << combinations[x];
}