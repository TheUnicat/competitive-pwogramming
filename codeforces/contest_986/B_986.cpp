//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, b, c;
        cin >> n >> b >> c;
        if (c >= n) cout << n << endl;
        else if (b == 0 && c < (n - 2)) cout << "-1" << endl;
        else if (b == 0) cout << n - 1 << endl;
        else {
            ll steps = c;
            ll new_steps = n - c - 1;
            new_steps -= ((new_steps) / b);
            steps += new_steps;
            cout << steps << endl;
        }
    }
}

