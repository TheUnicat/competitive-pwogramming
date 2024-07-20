//
// Created by TheUnicat on 2024-07-18.
//

#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > test_case(n, vector<int>(m));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> test_case[j][k];
            }
        }
        if (n == 1 && m == 1) {
            cout << -1 << endl;
            continue;
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j == n - 1 && k == m - 1) {
                    cout << test_case[0][0] << " ";
                    continue;
                }
                else if (k == m - 1) {
                    cout << test_case[j + 1][0] << endl;
                }
                else {
                    cout << test_case[j][k + 1] << " ";
                }
            }
        }
        cout << endl;
    }
}
