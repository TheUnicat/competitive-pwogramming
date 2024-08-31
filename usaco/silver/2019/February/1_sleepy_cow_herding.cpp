//
// Created by TheUnicat on 2024-07-23.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

int main() {
    ifstream infile("herding.in");
    infile >> n;
    vector<int> cow_positions(n);
    vector<int> cow_diffs;
    for (int i = 0; i < n; i++) infile >> cow_positions[i];
    infile.close();
    sort(cow_positions.begin(), cow_positions.end());
    for (int i = 0; i < n - 1; i++) {
        int diff = cow_positions[i + 1] - cow_positions[i] - 1;
        cow_diffs.push_back(diff);
    }

    int max = cow_positions[n - 1] - cow_positions[0] - n + 1;


    if (cow_diffs[n - 2] > 0 && cow_diffs[0] > 0) {
        max -= min(cow_diffs[n - 2], cow_diffs[0]);
    }

    int max_cow_window = 0;
    for (int i = 0; i < n - 1; i++) {
        int start = cow_positions[i];
        if (start + n - 1 > cow_positions[n - 1]) continue;
        int cow_count = 1;
        for (int j = i + 1; j < n; j++) {
            if (cow_positions[j] < start + n) {
                cow_count++;
            }
            else {
                break;
            }
        }
        if (cow_count > max_cow_window) {
            max_cow_window = cow_count;
        }
    }

    int min_moves;

    if (max_cow_window == n) min_moves = 0;
    else if (max_cow_window == n - 1) {
        if ((cow_diffs[0] > 1 && cow_diffs[n - 2] == 0) || (cow_diffs[n - 2] > 1 && cow_diffs[0] == 0)) min_moves = 2;
        else min_moves = 1;
    }
    else min_moves = n - max_cow_window;

    ofstream outfile("herding.out");
    outfile << min_moves << endl << max;
    outfile.close();
}
