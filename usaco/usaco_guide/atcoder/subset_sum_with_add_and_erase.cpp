//
// Created by TheUnicat on 2024-08-25.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int mod_n = 998244353;
vector<ll> combinations(5001, 0);

char sign;
int ball_val;
int q, k;

int main() {
    cin >> q >> k;
    combinations[0] = 1;
    for (int i = 0; i < q; i++) {
        cin >> sign >> ball_val;
        if (sign == '+') {
            for (int j = k; j >= ball_val; j--) {
                combinations[j] += combinations[j - ball_val];
                combinations[j] %= mod_n;
            }
        }
        else {
            for (int j = 0; j <= k - ball_val; j++) {
                combinations[j + ball_val] += mod_n - combinations[j];
                combinations[j + ball_val] %= mod_n;
            }
        }

        cout << combinations[k] << endl;
    }
}