//
// Created by TheUnicat on 2024-07-22.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, k;

int main() {
    ifstream infile("diamond.in");
    infile >> n >> k;
    vector<int> diamonds(n);
    vector<int> max_diamonds_from_x(n);
    vector<int> max_diamonds_after_x(n);
    for (int i = 0; i < n; i++) {
        infile >> diamonds[i];
    }
    infile.close();
    sort(diamonds.begin(), diamonds.end());

    int start = 0, end = 0;
    while (start < n) {
        if (diamonds[end] - diamonds[start] <= k) {
            if (end != n - 1) {
                end++;
            }
            else {
                max_diamonds_from_x[start] = end - start + 1;
                start++;
            }
        }
        else {
            max_diamonds_from_x[start] = end - start;
            start++;
        }
    }


    max_diamonds_after_x[n - 1] = 0;
    for (int i = n - 1; i > 0; i--) {
        max_diamonds_after_x[i - 1] = max(max_diamonds_after_x[i], max_diamonds_from_x[i]);
    }

    int max_diamonds = 0;
    for (int i = 0; i < n; i++) {
        max_diamonds = max(max_diamonds, max_diamonds_from_x[i] + max_diamonds_after_x[i + max_diamonds_from_x[i] - 1]);
    }

    ofstream outfile("diamond.out");
    outfile << max_diamonds;
    outfile.close();
}
