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
        int biggest_diff = 0;
        cin >> n;
        vector<int> test(n);
        for (int j = 0; j < n; j++) cin >> test[j];

        int biggest = -1100000000;

        for (int j = 0; j < n; j++) {
            if (test[j] > biggest) {
                biggest = test[j];
                continue;
            }

            int diff = biggest - test[j];
            if (diff > biggest_diff) biggest_diff = diff;
        }


        if (biggest_diff != 0) cout << ((int) log2(biggest_diff) + 1) << endl;
        else cout << 0 << endl;
    }
}