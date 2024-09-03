//
// Created by TheUnicat on 2024-09-03.
//

#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<char> > test_case(n, vector<char>(4)) ;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> test_case[j][k];
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k < 4; k++) {
                if (test_case[j][k] == '#') cout << (k + 1) << " ";
            }
        }
        cout << endl;
    }
}