//
// Created by TheUnicat on 2024-11-28.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int mod_n = 1e9 + 7;
vector<vector<int>> edges;

int main() {
    cin >> n >> m;
    vector<vector<int>> dp((1 << n), vector<int>(n, 0));
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
    }

    dp[1][0] = 1;
    for (int j = 0; j < (1 << n); j++) {
        for (int i = 0; i < n; i++) {
            if (dp[j][i] == 0) continue;
            for (int edge : edges[i]) {
                if (j & (1 << edge)) continue;
                dp[j | (1 << edge) ][edge] += dp[j][i];
                dp[j | (1 << edge) ][edge] %= mod_n;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}