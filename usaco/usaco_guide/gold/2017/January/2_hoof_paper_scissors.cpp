//
// Created by TheUnicat on 2024-08-27.
//

#include <fstream>
#include <vector>
using namespace std;

int n, k;

vector<char> fj_moves(100000);
vector<vector<vector<int> > > dp(3, vector<vector<int> >(21, vector<int>(100000, -1)));

int main() {
    ifstream infile("hps.in");
    infile >> n >> k;

    for (int i = 0; i < n; i++) {
        char hand;
        infile >> hand;
        fj_moves[i] = hand;
    }
    infile.close();

    dp[0][k][n - 1] = 0;
    dp[1][k][n - 1] = 0;
    dp[2][k][n - 1] = 0;

    for (int pos = n - 1; pos >= 0; pos--) {
        for (int curr_k = k; curr_k >= 0; curr_k--) {
            for (int hoof = 0; hoof < 3; hoof++) {
                if (dp[hoof][curr_k][pos] == -1) continue;
                if ((hoof == 0 && fj_moves[pos] == 'S') ||
                    (hoof == 1 && fj_moves[pos] == 'H') ||
                    (hoof == 2 && fj_moves[pos] == 'P')) dp[hoof][curr_k][pos]++;

                int curr_reward = dp[hoof][curr_k][pos];

                if (pos == 0) continue;
                dp[hoof][curr_k][pos - 1] = max(dp[hoof][curr_k][pos - 1], curr_reward);
                if (curr_k == 0) continue;
                if (hoof != 0) dp[0][curr_k - 1][pos - 1] = max(dp[0][curr_k - 1][pos - 1], curr_reward);
                if (hoof != 1) dp[1][curr_k - 1][pos - 1] = max(dp[1][curr_k - 1][pos - 1],curr_reward);
                if (hoof != 2) dp[2][curr_k - 1][pos - 1] = max(dp[2][curr_k - 1][pos - 1],curr_reward);
            }
        }
    }

    int max_reward = dp[0][0][0];
    for (int hoof = 0; hoof < 3; hoof++) {
        for (int final_k = 0; final_k <= k; final_k++) {
            max_reward = max(max_reward, dp[hoof][final_k][0]);
        }
    }

    ofstream outfile("hps.out");
    outfile << max_reward;
    outfile.close();
}