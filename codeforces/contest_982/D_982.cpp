//
// Created by TheUnicat on 2024-10-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int t;
int n, m;

int main() {
    cin >> t;
    while (t) {
        --t;
        cin >> n >> m;
        vector<ll> n_prefix(n + 1);
        n_prefix[0] = 0;
        vector<int> m_arr(m);
        for (int i = 1; i < n + 1; i++) {
            cin >> n_prefix[i];
            if (i > 0) n_prefix[i] += n_prefix[i - 1];
        }
        for (int i = 0; i < m; i++) cin >> m_arr[i];

        vector<vector<int>> dp(n + 1, vector<int>(m, 10e8));

        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != m - 1) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                ll max_val = m_arr[j] + n_prefix[i];
                int new_idx = (int) distance(n_prefix.begin(), upper_bound(n_prefix.begin(), n_prefix.end(), max_val)) - 1;

                dp[new_idx][j] = min(dp[new_idx][j], dp[i][j] + m - j - 1);
            }
        }

        int min_cost = 10e8;
        for (int val : dp[n]) {
            min_cost = min(min_cost, val);
        }

        if (min_cost == 10e8) cout << -1;
        else cout << min_cost;
        cout << endl;
    }
}