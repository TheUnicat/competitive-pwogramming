//
// Created by TheUnicat on 2024-09-29.
//

#include <iostream>
using namespace std;
using ll = long long;

ll t, b, c, d;
ll truth_table[2][2][2];

int main() {
    //b, c, d -> a;
    truth_table[0][0][0] = 0;
    truth_table[0][0][1] = 1;
    truth_table[0][1][0] = 0;
    truth_table[1][0][0] = 0;
    truth_table[0][1][1] = 1;
    truth_table[1][0][1] = 0;
    truth_table[1][1][0] = 1;
    truth_table[1][1][1] = 0;

    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> b >> c >> d;
        ll a = 0;
        for (ll j = 0; j <= 62; j++) {
            ll cmp = 1LL << j;
            a |= truth_table[((b & cmp) != 0)][((c & cmp) != 0)][((d & cmp) != 0)] << j;
        }
        if ((a | b) - (a & c) == d) cout << a;
        else cout << -1;
        cout << endl;
    }
}


