//
// Created by TheUnicat on 2024-08-20.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int h, k;
int max_len = 500000;
int min_len = 0;
int mid;

vector<int> houses;

bool valid_len(int hose_len) {
    hose_len *= 2;
    for (int start = 0; start < h; start++) {
        vector<bool> covered(h, false);
        int hydrants_placed = 0;
        int n_covered = 0;

        for (int i = start; i < h; i++) {
            if (covered[i]) continue;
            hydrants_placed++;
            if (hydrants_placed > k) break;

            int current_pos = houses[i];
            covered[i] = true;
            n_covered++;
            bool extends = true;

            for (int j = i + 1; j < h; j++) {
                if (houses[j] - current_pos <= hose_len) {
                    covered[j] = true;
                    n_covered++;
                }
                else {
                    extends = false;
                    break;
                }
            }

            if (extends) {
                for (int j = 0; j < i; j++) {
                    if (houses[j] + 1000000 - current_pos <= hose_len) {
                        covered[j] = true;
                        n_covered++;
                    }
                    else break;
                }
            }

            if (n_covered >= h) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> h;
    houses.resize(h);
    for (int i = 0; i < h; i++) cin >> houses[i];
    sort(houses.begin(), houses.end());
    cin >> k;

    int min_solution = 1000000;

    while (max_len >= min_len) {
        mid = min_len + (max_len - min_len) / 2;
        if (valid_len(mid)) {
            min_solution = mid;
            max_len = mid - 1;
        }
        else min_len = mid + 1;
    }

    cout << min_solution;
}