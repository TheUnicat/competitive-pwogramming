//
// Created by TheUnicat on 2024-08-04.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int t;
int n;
vector<int> test;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int steps = 0;
        test.clear();
        test.resize(n);
        for (int j = 0; j < n; j++) cin >> test[j];
        sort(test.begin(), test.end());

        bool same = true;
        for (int j = 1; j < n; j++) {
            if (test[j] % 2 != test[j - 1] % 2) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << 0 << endl;
            continue;
        }

        int latest_odd = -1;
        vector<int> evens;
        for (int j = 0; j < n; j++) {
            if (test[j] % 2 == 1) latest_odd = j;
        }
        for (int j = latest_odd - 1; j >= 0; j--) {
            if (test[j] % 2 == 0) {
                evens.push_back(test[j]);
            }
        }

        ll even_sum = test[latest_odd];
        for (int even : evens) {
            even_sum += even;
            if (even_sum >= test[n - 1]) break;
        }

        for (int j = latest_odd + 1; j < n; j++) {
            if (test[j] % 2 == 0) {
                if (test[j] > even_sum) {
                    steps++;
                    break;
                }
                else even_sum += test[j];
            }
        }

        for (int j = 0; j < n; j++) {
            if (test[j] % 2 == 0) steps++;
        }


        cout << steps << endl;
    }
}