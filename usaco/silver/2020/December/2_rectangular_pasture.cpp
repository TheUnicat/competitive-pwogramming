//
// Created by TheUnicat on 2024-07-06.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll subsets = 1;

int main() {
    cin >> n;
    vector<pair<int, int> > cows(n);
    vector<pair<int, int> > cows_reversed(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows_reversed[i].second = cows[i].first;
        cows_reversed[i].first = cows[i].second;
    }
    sort(cows.begin(), cows.end());
    sort(cows_reversed.begin(), cows_reversed.end());

    for (int i = 0; i < n; i++) {
        auto cow = cows[i];
        for (int j = 0; j < n; j++) {
            if (cows_reversed[j].first == cow.second) {
                cows[i].second = j;
                cows[i].first = i;
                break;
            }
        }
    }

    vector<vector<int> > prefix_sum(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cows[i].second == j) {
                prefix_sum[i + 1][j + 1]++;
            }
            if (i > 0) prefix_sum[i + 1][j + 1] += prefix_sum[i][j + 1];
            if (j > 0) prefix_sum[i + 1][j + 1] += prefix_sum[i + 1][j];
            if (i > 0 && j > 0) prefix_sum[i + 1][j + 1] -= prefix_sum[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> cow_one, cow_two;
            cow_one = cows[i];
            cow_two = cows[j];
            int min_y = min(cow_one.second, cow_two.second);
            int max_y = max(cow_one.second, cow_two.second);
            int min_x = i;
            int max_x = j;

            int above = prefix_sum[max_x + 1][n] - prefix_sum[min_x][n] - prefix_sum[max_x + 1][max_y] + prefix_sum[min_x][max_y];
            int below = prefix_sum[max_x + 1][min_y + 1] - prefix_sum[min_x][min_y + 1];

            subsets += above * below;
        }
    }

    cout << subsets + n;
}

