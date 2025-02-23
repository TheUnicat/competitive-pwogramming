//
// Created by TheUnicat on 2025-02-22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll n, m, k;
ll steps, half;
vector<vector<ll>> grid;
vector<vector<vector<ll>>> xor_one, xor_two;

int main() {
    cin >> n >> m >> k;
    steps = n + m - 2;
    half = steps / 2;
    grid.resize(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) cin >> grid[i][j];
    xor_one.resize(n, vector<vector<ll>>(m)), xor_two.resize(n, vector<vector<ll>>(m));
    for (ll i = 0; i < (1 << half); i++) {
        ll c_x = 0, c_y = 0;
        ll c_xor = grid[c_x][c_y];
        for (ll j = 0; j < half; j++) {
            if (1 << j & i) c_y++;
            else c_x++;
            if (c_x == n || c_y == m) break;
            c_xor ^= grid[c_x][c_y];
        }
        if (c_x == n || c_y == m) continue;
        xor_one[c_x][c_y].push_back(c_xor);
    }
    for (ll i = 0; i < (1 << (steps - half)); i++) {
        ll c_x = n - 1, c_y = m - 1;
        ll c_xor = grid[c_x][c_y];
        for (ll j = 0; j < steps - half; j++) {
            if (1 << j & i) c_y--;
            else c_x--;
            if (c_x < 0 || c_y < 0) break;
            c_xor ^= grid[c_x][c_y];
        }
        if (c_x < 0 || c_y < 0) continue;
        xor_two[c_x][c_y].push_back(c_xor);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) {
        sort(xor_one[i][j].begin(), xor_one[i][j].end()), sort(xor_two[i][j].begin(), xor_two[i][j].end());
        ll left = 0;
        while (left < xor_one[i][j].size()) {
            ll val = xor_one[i][j][left];
            ll right = (ll) distance(xor_one[i][j].begin(), upper_bound(xor_one[i][j].begin(), xor_one[i][j].end(), val)) - 1;
            ll left_len = right - left + 1;
            left = right + 1;
            ll target = k ^ val ^ grid[i][j];
            ans += left_len * ((ll) distance(lower_bound(xor_two[i][j].begin(), xor_two[i][j].end(), target), upper_bound(xor_two[i][j].begin(), xor_two[i][j].end(), target)));
        }
    }

    cout << ans << endl;
}