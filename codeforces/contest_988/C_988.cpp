//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
using namespace std;

int t;


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool solvable = false;
        int n;
        cin >> n;

        if (n < 5) cout << -1 << endl;
        else {
            for (int j = 1; j <= n; j += 2) {
                if (j == 5) continue;
                cout << j << " ";
            }

            cout << 5 << " " << 4 << " ";
            for (int j = 2; j <= n; j += 2) {
                if (j == 4) continue;
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

//1 3 5 7 9 11 2 4 6 8 10 12

//1 3 2 4