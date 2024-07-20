//
// Created by TheUnicat on 2024-07-18.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        set<int> overflow_points;
        vector<int> real_overflow_points;
        ll n, x;
        ll good_subarrays = 0;
        cin >> n >> x;
        vector<ll> prefix_sum(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cin >> prefix_sum[j];
        }
        for (int j = 0; j < n; j++) {
            bool end = false;
            for (int point : real_overflow_points) {
                if (point == j) end = true;
            }
            if (end == true) continue;
            int overflow_count = 0;
            ll g = 0;
            for (int k = j; k < n; k++) {
                g += prefix_sum[k + 1];
                if (g > x) {
                    g = 0;
                    if (prefix_sum[k + 1] > x) {
                        int overflow_size = overflow_points.size();
                        //cout << "insert " << k << endl;
                        overflow_points.insert(k);
                        real_overflow_points.push_back(k);
                        if (overflow_points.size() > overflow_size) overflow_count++;
                    }
                }
                else {
                    good_subarrays += 1 + overflow_count;
                }
            }
        }
        cout << good_subarrays << endl;
    }
}
