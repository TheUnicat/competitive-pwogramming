//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
#include <string>
#include <vector>
using ll = long long;
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll sum = 0;
        string test_case;
        cin >> test_case;
        vector<pair<int, int> > prefix_sums(test_case.length(), make_pair(0, 0));
        for (int j = 0; j < test_case.length(); j++) {
            if (test_case[j] == '1') {
                prefix_sums[j].second++;
            }
            else prefix_sums[j].first++;

            if (j != 0) {
                prefix_sums[j].first += prefix_sums[j - 1].first;
                prefix_sums[j].second += prefix_sums[j - 1].second;
            }
        }

        for (int size = 1; size <= test_case.length(); size++) {
            for (int left = 0; left + size <= test_case.length(); left++) {
                int one_count = prefix_sums[left + size - 1].first;
                int two_count = prefix_sums[left + size - 1].second;
                if (left != 0) {
                    one_count -= prefix_sums[left - 1].first;
                    two_count -= prefix_sums[left - 1].second;
                }

                if (one_count == two_count) sum++;
            }
        }

        cout << sum % 1000000007 << endl;
    }
}