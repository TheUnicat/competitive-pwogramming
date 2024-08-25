//
// Created by TheUnicat on 2024-08-25.
//

#include <iostream>
#include <vector>
using namespace std;

int n, x;
int mod_n = 1000000007;
vector<int> combinations(1000001, 0);
vector<int> coins(100);

int main() {
    combinations[0] = 1;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];

    for (int j = 0; j < n; j++) {
        int coin = coins[j];
        for (int i = 0; i <= x; i++) {
            if (i + coin <= x) {
                combinations[i + coin] += combinations[i];
                combinations[i + coin] %= mod_n;
            }
            else break;
        }
    }

    cout << combinations[x];
}