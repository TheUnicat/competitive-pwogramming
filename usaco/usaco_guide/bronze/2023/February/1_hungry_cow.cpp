//
// Created by TheUnicat on 2024-08-28.
//

#include <iostream>
using namespace std;
using ll = long long;

ll n, t;
ll curr_bales = 0;
ll eaten = 0;

int main() {
    cin >> n >> t;
    ll d, b, prev_d, prev_b;
    cin >> d >> b;
    prev_d = d;
    curr_bales += b;
    n--;

    while (n > 0) {
        n--;
        cin >> d >> b;

        ll curr_eaten = min(d - prev_d, curr_bales);
        curr_bales -= curr_eaten;
        eaten += curr_eaten;

        curr_bales += b;
        prev_d = d;
    }

    eaten += min(t - prev_d + 1, curr_bales);

    cout << eaten;
}