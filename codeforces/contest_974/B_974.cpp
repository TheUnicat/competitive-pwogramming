//
// Created by TheUnicat on 2024-09-21.
//

#include <iostream>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int year, longevity;
        cin >> year >> longevity;

        bool odd;
        if (year % 2 == 1) odd = true;
        else odd = false;
        int n_odds;
        if (odd == true) {
            n_odds = (longevity - 1) / 2 + 1;
        }
        else {
            n_odds = longevity / 2;
        }

        if (n_odds % 2 == 1) {
            odd = true;
        }
        else odd = false;

        if (odd == false) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}