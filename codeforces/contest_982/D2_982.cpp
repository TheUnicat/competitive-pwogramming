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
int mod_n = 1000000007;

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

        vector<vector<int>> dp_copy(n + 1, vector<int>(m, 10e8));
        dp_copy[0][0] = 0;
        vector<vector<int>> paths(n + 1, vector<int>(m, 0));
        paths[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != m - 1) dp_copy[i][j + 1] = min(dp_copy[i][j + 1], dp_copy[i][j]);
                if (dp_copy[i][j] == dp[i][j + 1]) paths[i][j + 1] += paths[i][j];
                ll max_val = m_arr[j] + n_prefix[i];
                int new_idx = (int) distance(n_prefix.begin(), upper_bound(n_prefix.begin(), n_prefix.end(), max_val)) - 1;

                dp_copy[new_idx][j] = min(dp_copy[new_idx][j], dp_copy[i][j] + m - j - 1);
                if (dp_copy[i][j] + m - j - 1 == dp[new_idx][j]) paths[new_idx][j] += paths[i][j];
            }
        }

        int min_cost = 10e8;
        int min_cost_n_optimal_paths = 0;
        for (int i = 0; i < dp[n].size(); i++) {
            int val = dp[n][i];
            if (val < min_cost) {
                min_cost = min(min_cost, val);
                min_cost_n_optimal_paths = paths[n][i];
            }
            else if (val == min_cost) min_cost_n_optimal_paths += paths[n][i];
        }

        if (min_cost == 10e8) cout << -1;
        else cout << min_cost << " " << min_cost_n_optimal_paths;
        cout << endl;
    }
}