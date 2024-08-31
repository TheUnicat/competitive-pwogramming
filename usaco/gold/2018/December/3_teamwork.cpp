//
// Created by TheUnicat on 2024-08-28.
//

#include <fstream>
#include <vector>
using namespace std;

int n, k;
vector<int> cows(10000);
vector<int> dp(10000, 0);

int main() {
    ifstream infile("teamwork.in");
    infile >> n >> k;

    for (int i = 0; i < n; i++) infile >> cows[i];
    infile.close();

    for (int pos = 0; pos < n; pos++) {
        int group_max = cows[pos];
        for (int i = pos; i >= max(0, pos - k + 1); i--) {
            group_max = max(group_max, cows[i]);

            if (i == 0) {
                dp[pos] = group_max * (pos - i + 1);
            }
            else {
                dp[pos] = max(dp[pos], dp[i - 1] + group_max * (pos - i + 1));
            }
        }
    }

    ofstream outfile("teamwork.out");
    outfile << dp[n - 1];
    outfile.close();
}
