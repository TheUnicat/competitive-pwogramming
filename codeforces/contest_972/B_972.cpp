//
// Created by TheUnicat on 2024-09-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, q, pos;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> q;
        vector<int> teachers(m);
        vector<int> queries(q);
        for (int j = 0; j < m; j++) {
            cin >> teachers[j];
        }
        sort(teachers.begin(), teachers.end());
        for (int j = 0; j < q; j++) {
            int query;
            cin >> query;
            auto upper_it = lower_bound(teachers.begin(), teachers.end(), query);
            if (upper_it == teachers.begin()) {
                cout << (*upper_it - 1) << endl;
            }
            else if (upper_it == teachers.end()) {
                upper_it--;
                cout << (n - (*upper_it)) << endl;
            }
            else {
                int higher = *upper_it;
                upper_it--;
                int lower = *upper_it;
                cout << (higher - lower) / 2 << endl;
            }
        }
    }
}