//
// Created by TheUnicat on 2024-12-24.
//

#include <iostream>
using namespace std;
using ll = long long;

ll t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        ll ans = 0;
        while (n > 3) {
            n /= 4;
            ans++;
        }

        ans = 1 << ans;
        cout << ans << endl;
    }
}