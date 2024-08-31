//
// Created by TheUnicat on 2024-08-31.
//

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int n, k;
vector<int> snakes(400);
vector<vector<int> > dp(400, vector<int>(401, INT32_MAX));
int snake_sum = 0;

int main() {
    ifstream infile("snakes.in");
    infile >> n >> k;
    for (int i = 0; i < n; i++) infile >> snakes[i];
    for (int i = 0; i < n; i++) snake_sum += snakes[i];
    infile.close();

    dp[0][k] = 0;

    int largest_group = 0;

    for (int i = 0; i < n; i++) {
        largest_group = max(largest_group, snakes[i]);
        dp[i][0] = largest_group * (i + 1);
        for (int j = 1; j <= k; j++) {
            dp[i][j] = largest_group * (i + 1);
            int curr_net_size = snakes[i];
            for (int c = i - 1; c >= 0; c--) {
                if (dp[c][j - 1] == INT32_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[c][j - 1] + (i - c) * curr_net_size);
                curr_net_size = max(curr_net_size, snakes[c]);
            }
        }
    }

    int min_loss = INT32_MAX;
    for (int i = 0; i <= k; i++) {
        if (dp[n - 1][i] == -1) continue;
        min_loss = min(min_loss, dp[n - 1][i]);
    }

    ofstream outfile("snakes.out");
    outfile << min_loss - snake_sum;
    outfile.close();
}