//
// Created by TheUnicat on 2024-12-28.
//

#include <iostream>
#include <vector>
using namespace std;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<pair<int, int>> bounds(n);
        vector<int> not_unique(2 * n + 1, 0);
        vector<int> not_unique_prefix(2 * n + 1, 0);
        for (int j = 0; j < n; j++) cin >> bounds[j].first >> bounds[j].second;
        for (int j = 0; j < n; j++) {
            if (bounds[j].first == bounds[j].second) not_unique[bounds[j].first]++;
        }
        for (int j = 1; j <= 2 * n; j++) {
            if (not_unique[j] > 0) not_unique_prefix[j]++;
            not_unique_prefix[j] += not_unique_prefix[j - 1];
        }

        for (int j = 0; j < n; j++) {
            if (bounds[j].second == bounds[j].first) {
                if (not_unique[bounds[j].first] == 1) {
                    cout << 1;
                }
                else cout << 0;
            }
            else {
                if (not_unique_prefix[bounds[j].second] - not_unique_prefix[bounds[j].first - 1] < bounds[j].second - bounds[j].first + 1) {
                    cout << 1;
                }
                else cout << 0;
            }
        }
        cout << endl;
    }
}