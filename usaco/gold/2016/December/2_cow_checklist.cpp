//
// Created by TheUnicat on 2024-09-09.
//

#include <fstream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> dp(1001, vector<pair<int, int>>(1001, make_pair(INT32_MAX - 10000000, INT32_MAX - 1000000)));
vector<pair<int, int>> holsteins(1001);
vector<pair<int, int>> guernseys(1001);
int h, g;

int sq(int num) {
    return num * num;
}

int distance(pair<int, int> a, pair<int, int> b) {
    return sq(a.first - b.first) + sq(a.second - b.second);
}

int main() {
    dp[1][0].first = 0;
    ifstream infile("checklist.in");
    infile >> h >> g;
    for (int i = 0; i < h; i++) {
        infile >> holsteins[i].first >> holsteins[i].second;
    }
    for (int i = 0; i < g; i++) {
        infile >> guernseys[i].first >> guernseys[i].second;
    }
    infile.close();

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= g; j++) {
            if (i == h && j < i) break;
            //for when last cow is holstein
            pair<int, int> curr_pos = holsteins[i - 1];
            int holstein_distance = distance(holsteins[i], curr_pos);
            dp[i + 1][j].first = min(dp[i + 1][j].first, dp[i][j].first + holstein_distance);
            int guernsey_distance = distance(guernseys[j], curr_pos);
            dp[i][j + 1].second = min(dp[i][j + 1].second, dp[i][j].first + guernsey_distance);

            if (j == 0) continue;
            //for when last cow is guernsey
            curr_pos = guernseys[j - 1];
            holstein_distance = distance(holsteins[i], curr_pos);
            dp[i + 1][j].first = min(dp[i + 1][j].first, dp[i][j].second + holstein_distance);
            guernsey_distance = distance(guernseys[j], curr_pos);
            dp[i][j + 1].second = min(dp[i][j + 1].second, dp[i][j].second + guernsey_distance);
        }
    }

    ofstream outfile("checklist.out");
    outfile << dp[h][g].first;
    outfile.close();
}