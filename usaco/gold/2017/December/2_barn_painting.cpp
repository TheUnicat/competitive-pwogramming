//
// Created by TheUnicat on 2025-01-23.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

ll n, k, mod = 1e9 + 7;
vector<vector<ll>> dp;
vector<vector<ll>> edges;
vector<ll> colors;
vector<bool> visited;

void dfs(ll v, ll p) {
    if (colors[v] != -1) {
        for (ll i = 0; i < 3; i++) if (i != colors[v]) dp[v][i] = 0;
    }
    visited[v] = true;
    for (ll color = 0; color < 3; color++) {
        if (colors[v] != -1 && color != colors[v]) continue;
        for (ll c : edges[v]) {
            ll child_sum = 0;
            if (c == p) continue;
            if (!visited[c]) dfs(c, v);
            for (ll i = 0; i < 3; i++) if (i != color) child_sum += dp[c][i];
            dp[v][color] *= child_sum;
            dp[v][color] %= mod;
        }
    }
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin >> n >> k;
    dp.resize(n, vector<ll>(3, 1));
    edges.resize(n), colors.resize(n, -1);
    visited.resize(n, false);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (ll i = 0; i < k; i++) {
        ll b, c;
        cin >> b >> c;
        b--, c--;
        colors[b] = c;
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % mod << endl;
}