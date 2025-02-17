//
// Created by TheUnicat on 2025-02-16.
//

#include <iostream>
#include <string>
using namespace std;
int t, n;
string str;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> str;
        int ans = 0;
        bool found_zero = true, found_one = false;
        for (int j = 0; j < n; j++) {
            if (str[j] == '0') {
                found_zero = true;
                if (found_one) {
                    ans++;
                    found_one = false;
                }
            }
            else {
                found_one = true;
                if (found_zero) {
                    found_zero = false;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}