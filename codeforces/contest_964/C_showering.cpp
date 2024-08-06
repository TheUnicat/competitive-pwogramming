//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, s, m;
        cin >> n >> s >> m;

        bool can_shower = false;
        int last_time = 0;

        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            if (l - s >= last_time) can_shower = true;
            else if (j == n - 1 && m - r >= s) can_shower = true;

            last_time = r;
        }

        if (can_shower) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}