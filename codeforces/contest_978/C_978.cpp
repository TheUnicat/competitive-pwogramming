//
// Created by TheUnicat on 2024-10-13.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t > 0) {
        t--;
        int n;
        cin >> n;
        string row_one, row_two;
        vector<vector<int>> dp(n + 1, vector<int>(7, -1));
        dp[0][3] = 0;
        cin >> row_one >> row_two;
        for (int i = 0; i < n + 1; i++) {
            for (int j = -3; j < 4; j++) {
                if (i + j < 0 || i + j > n) continue;
                if (dp[i][j + 3] == -1) continue;
                //dp on top element
                if (i + 3 <= n && j >= 0) {
                    int alvaro_votes = 0;
                    if (row_one[i] == 'A') alvaro_votes++;
                    if (row_one[i + 1] == 'A') alvaro_votes++;
                    if (row_one[i + 2] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i + 3][j] = max(dp[i + 3][j], dp[i][j + 3] + 1);
                    else dp[i + 3][j] = max(dp[i + 3][j], dp[i][j + 3]);
                }

                if (i + 2 <= n && j == 1) {
                    int alvaro_votes = 0;
                    if (row_one[i] == 'A') alvaro_votes++;
                    if (row_one[i + 1] == 'A') alvaro_votes++;
                    if (row_two[i + j] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i + 2][3] = max(dp[i + 2][3], dp[i][4] + 1);
                    else dp[i + 2][3] = max(dp[i + 2][3], dp[i][4]);
                }

                if (i + 2 <= n && j == 0) {
                    int alvaro_votes = 0;
                    if (row_one[i] == 'A') alvaro_votes++;
                    if (row_one[i + 1] == 'A') alvaro_votes++;
                    if (row_two[i] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i + 2][2] = max(dp[i + 2][2], dp[i][3] + 1);
                    else dp[i + 2][2] = max(dp[i + 2][2], dp[i][3]);

                    alvaro_votes = 0;
                    if (row_one[i] == 'A') alvaro_votes++;
                    if (row_two[i + 1] == 'A') alvaro_votes++;
                    if (row_two[i] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i + 1][4] = max(dp[i + 1][4], dp[i][3] + 1);
                    else dp[i + 1][4] = max(dp[i + 1][4], dp[i][3]);
                }
                //dp on bottom element
                if (i + 1 <= n && j == -1) {
                    int alvaro_votes = 0;
                    if (row_two[i - 1] == 'A') alvaro_votes++;
                    if (row_two[i] == 'A') alvaro_votes++;
                    if (row_one[i] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i + 1][3] = max(dp[i + 1][3], dp[i][2] + 1);
                    else dp[i + 1][3] = max(dp[i + 1][3], dp[i][2]);
                }

                if (i + j + 3 <= n && j <= 0) {
                    int alvaro_votes = 0;
                    if (row_two[i + j] == 'A') alvaro_votes++;
                    if (row_two[i + j + 1] == 'A') alvaro_votes++;
                    if (row_two[i + j + 2] == 'A') alvaro_votes++;
                    if (alvaro_votes >= 2) dp[i][j + 6] = max(dp[i][j + 6], dp[i][j + 3] + 1);
                    else dp[i][j + 6] = max(dp[i][j + 6], dp[i][j + 3]);
                }
            }
        }


        cout << dp[n][3] << endl;
    }
}