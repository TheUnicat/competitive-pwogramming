//
// Created by TheUnicat on 2024-12-07.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> bacteria;

int main() {
    cin >> n;
    bacteria.resize(n);
    for (int i = 0; i < n; i++) cin >> bacteria[i];

    ll ans = 0, curr_pos_offset = 0, curr_constant_offset = 0;
    for (ll i = 0; i < n; i++) {
        ll curr_num = bacteria[i];
        curr_num += curr_pos_offset * i;
        curr_num += curr_constant_offset;
        ans += abs(curr_num);
        curr_pos_offset += -curr_num;
        curr_constant_offset += -(curr_num) * (1 - i);
    }

    cout << ans << endl;
}

