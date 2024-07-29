//
// Created by TheUnicat on 2024-07-29.
//

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n;

int main() {
    ifstream infile("angry.in");
    infile >> n;
    vector<ll> cows(n);
    vector<ll> diffs(n - 1);

    vector<ll> min_from_left;
    vector<ll> min_from_right;
    for (int i = 0; i < n; i++) {
        infile >> cows[i];
        cows[i] *= 2;
    }
    infile.close();

    sort(cows.begin(), cows.end());
    for (int i = 1; i < n; i++) {
        diffs[i - 1] = cows[i] - cows[i - 1];
    }

    ll total_diff = cows[n - 1] - cows[0];

}