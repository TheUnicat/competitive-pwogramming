//
// Created by TheUnicat on 2024-09-10.
//

#include <fstream>
#include <vector>
#include <string>
using namespace std;

int max_val = 2000000000;
int n, m;
vector<pair<int, int>> john_pos(1001);
vector<pair<int, int>> bessie_pos(1001);
vector<vector<int>> dp(1001, vector<int>(1001, max_val));
string john_str, bessie_str;

int sq(int num) {
    return num * num;
}

int distance(pair<int, int> a, pair<int, int> b) {
    return sq(a.first - b.first) + sq(a.second - b.second);
}

int main() {
    ifstream infile("radio.in");
    infile >> n >> m;
    int curr_john_x, curr_john_y, curr_bessie_x, curr_bessie_y;
    infile >> curr_john_x >> curr_john_y >> curr_bessie_x >> curr_bessie_y;
    infile >> john_str >> bessie_str;
    for (int i = 0; i <= n; i++) {
        john_pos[i] = make_pair(curr_john_x, curr_john_y);
        if (i == n) break;
        if (john_str[i] == 'N') curr_john_y++;
        else if (john_str[i] == 'S') curr_john_y--;
        else if (john_str[i] == 'W') curr_john_x--;
        else curr_john_x++;
    }

    for (int i = 0; i <= m; i++) {
        bessie_pos[i] = make_pair(curr_bessie_x, curr_bessie_y);
        if (i == m) break;
        if (bessie_str[i] == 'N') curr_bessie_y++;
        else if (bessie_str[i] == 'S') curr_bessie_y--;
        else if (bessie_str[i] == 'W') curr_bessie_x--;
        else curr_bessie_x++;
    }

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != n) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + distance(john_pos[i + 1], bessie_pos[j]));
            }
            if (j != m) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + distance(bessie_pos[j + 1], john_pos[i]));
            }
            if (i != n && j != m) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + distance(bessie_pos[j + 1], john_pos[i + 1]));
            }
        }
    }

    ofstream outfile("radio.out");
    outfile << dp[n][m];
    outfile.close();
}