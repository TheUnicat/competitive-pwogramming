//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int j = 0; j < abs(m - n); j++) {
            cout << n - j << " ";
        }
        for (int j = 1; j <= m; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}