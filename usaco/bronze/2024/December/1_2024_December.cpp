#include <iostream>
using namespace std;
using ll = long long;

ll t;

int main() {
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll test;
        cin >> test;
        ll ans = 0;
        ll curr_num = 45;
        ll curr_range_max = 50;
        while (curr_num <= test) {
            ans += min(curr_range_max - 1, test) - curr_num + 1;
            curr_num *= 10;
            curr_num -= 5;
            curr_range_max *= 10;
        }

        cout << ans << endl;
    }
}

