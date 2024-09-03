//
// Created by TheUnicat on 2024-08-31.
//

#include <iostream>
#include <vector>
using namespace std;

int w, h;
int n;
vector<pair<int, int> > slabs(200);
vector<vector<int> > dp(601, vector<int>(601));

int main() {
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        int dim1, dim2;
        cin >> dim1 >> dim2;
        slabs[i] = make_pair(dim1, dim2);
    }

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            dp[i][j] = i * j;
        }
    }

    for (auto slab : slabs) {
        dp[slab.first][slab.second] = 0;
    }

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            for (int z = 1; z < i; z++) {
                dp[i][j] = min(dp[i][j], dp[i - z][j] + dp[z][j]);
            }

            for (int z = 1; z < j; z++) {
                dp[i][j] = min(dp[i][j], dp[i][j - z] + dp[i][z]);
            }
        }
    }

    cout << dp[w][h];
}