//
// Created by TheUnicat on 2024-08-24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> counts(1000002, 0);
int mod_n = 1000000007;
int n;

int get_count(int pos) {
    if (pos < 0) return 0;
    return counts[pos];
}


int main() {
    cin >> n;
    counts[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            counts[i] += get_count(i - j);
            counts[i] %= mod_n;
        }
    }

    cout << counts[n];
}