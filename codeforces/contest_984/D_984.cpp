//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        int count = 0;
        cin >> n >> m;
        vector<string> lines(n);
        vector<vector<bool>> has_substr(n, vector<bool>(m, false));
        for (int j = 0; j < n; j++) cin >> lines[j];


        for (int j = 0; j < min(n / 2, m / 2); j++) {
            char prev3 = '=', prev2 = '=', prev1 = '=', curr;
            for (int l = 0; l < 2; l++) {
                for (int k = j; k < m - j; k++) {
                    curr = lines[j][k];
                    if (prev3 == '1' && prev2 == '5' && prev1 == '4' && curr == '3' && !has_substr[j][k]) {
                        count++;
                        has_substr[j][k] = true;
                    }
                    prev3 = prev2, prev2 = prev1, prev1 = curr;
                }
                for (int k = j + 1; k < n - j; k++) {
                    curr = lines[k][m - j - 1];
                    if (prev3 == '1' && prev2 == '5' && prev1 == '4' && curr == '3' && !has_substr[k][m - j - 1]) {
                        count++;
                        has_substr[k][m - j - 1] = true;
                    }
                    prev3 = prev2, prev2 = prev1, prev1 = curr;
                }
                for (int k = m - j - 2; k >= j; k--) {
                    curr = lines[n - j - 1][k];
                    if (prev3 == '1' && prev2 == '5' && prev1 == '4' && curr == '3' && !has_substr[n - j - 1][k]) {
                        count++;
                        has_substr[n - j - 1][k] = true;
                    }
                    prev3 = prev2, prev2 = prev1, prev1 = curr;
                }
                for (int k = n - j - 2; k >= j + 1; k--) {
                    curr = lines[k][j];
                    if (prev3 == '1' && prev2 == '5' && prev1 == '4' && curr == '3' && !has_substr[k][j]) {
                        count++;
                        has_substr[k][j] = true;
                    }
                    prev3 = prev2, prev2 = prev1, prev1 = curr;
                }
            }
        }

        cout << count << endl;
    }
}