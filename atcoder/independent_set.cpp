//
// Created by TheUnicat on 2025-01-28.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;
int n;
vector<vector<int>> edges;
ll dp[100000][2];

void dfs(int v, int p) {
    ll white_ans = 1;
    ll black_ans = 1;
    for (int e : edges[v]) {
        if (e == p) continue;
        if (dp[e][0] == 0) dfs(e, v);
        black_ans *= dp[e][0];
        black_ans %= mod;
        white_ans *= (dp[e][0] + dp[e][1]);
        white_ans %= mod;
    }
    dp[v][0] = white_ans;
    dp[v][1] = black_ans;
}

int main() {
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    fill(dp[0], dp[0] + 10005, 0);
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}