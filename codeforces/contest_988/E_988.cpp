//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int query(int l, int r) {
    cout << "?" << " " << l << " " << r << endl;
    cout.flush();
    int num;
    cin >> num;
    return num;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        bool solvable = true;
        cin >> n;
        vector<int> known(n , - 1);
        vector<int> query_vals(n, -1);
        vector<int> prefix_zeroes(n, 0);
        for (int j = 1; j < n; j++) {
            int query_val = query(1, j + 1);
            query_vals[j] = query_val;
            if (j == 1) {
                if (query_val == 1) {
                    known[0] = 0;
                    known[j] = 1;
                    prefix_zeroes[0]++;
                    prefix_zeroes[j]++;
                }
            }
            else {
                prefix_zeroes[j] = prefix_zeroes[j - 1];
                if (query_val > query_vals[j - 1]) known[j] = 1;
                else if (query_val > 0) {
                    known[j] = 0;
                    prefix_zeroes[j]++;
                }
            }
        }


        if (known[0] == -1) {
            auto it = lower_bound(query_vals.begin(), query_vals.end(), 1);
            int idx = distance(query_vals.begin(), it);
            if (it == query_vals.end()) solvable = false;
            else {
                int zeroes = query_vals[idx] - prefix_zeroes[idx - 1];
                if (known[idx - 1] == 0) zeroes++;
                for (int j = idx - 1; j >= 0; j--) {
                    if (zeroes > 0) {
                        known[j] = 0;
                        zeroes--;
                    }
                    else known[j] = 1;
                }
            }
        }


        for (int j = 0; j < n; j++) {
            if (known[j] == -1) {
                solvable = false;
                break;
            }
        }


        cout << "!" << " ";
        if (!solvable) cout << "IMPOSSIBLE";
        else for (int val : known) cout << val;
        cout << endl;
    }
}


//000001