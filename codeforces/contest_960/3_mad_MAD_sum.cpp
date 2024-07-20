//
// Created by TheUnicat on 2024-07-20.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int length;
        cin >> length;
        vector<ll> test_case(length);
        for (int j = 0; j < length; j++) cin >> test_case[j];

        ll sum = 0;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < length; j++) sum += test_case[j];
            set<ll> duplicate_numbers;
            ll max_MAD_current = 0;
            for (int j = 0; j < length; j++) {
                if (test_case[j] > max_MAD_current) {
                    if (duplicate_numbers.find(test_case[j]) != duplicate_numbers.end()) {
                        max_MAD_current = test_case[j];
                    }
                    else duplicate_numbers.insert(test_case[j]);
                }
                test_case[j] = max_MAD_current;
            }
        }

        for (int j = 0; j < length; j++) sum += test_case[j] * (length - j);

        cout << sum << endl;
    }
}