//
// Created by TheUnicat on 2024-08-12.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        int seconds = 0;
        cin >> n;
        vector<int> test(n);
        for (int j = 0; j < n; j++) cin >> test[j];

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        int left = 1;
        while (test[left] >= test[left - 1]) {
                left++;
        }
        int min_value = test[left - 1];
        int max_diff = 0;

        for (int j = left; j < n; j++) {
            if (min_value - test[j] > max_diff) max_diff = min_value - test[j];
        }

        int num = 0;
        seconds = max_diff > 0 ? (int) log2(max_diff) + 1 : 0;

        cout << seconds << endl;
    }
}