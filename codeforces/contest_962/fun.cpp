//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
#include <cmath>
using ll = long long;
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll answer = 0;
        int a, b, c;
        int n, x;
        cin >> n >> x;

        if (x % 3 == 0) {
            a = x / 3;
            b = a;
            c = a;
        }
        else if (x % 3 == 2) {
            a = x / 3;
            b = a + 1;
            c = a + 1;
        }
        else {
            a = x / 3;
            b = a;
            c = a + 1;
        }

        if (a * (b + c) + b * c > n) {
            int max_cube = (int) sqrt(x / 3);
            while (true) {
                if (b <= c) {
                    b++;
                    if (a * (b + c) + b * c > n) {
                        b--; break;
                    }
                }
                else {
                    c++;
                    if (a * (b + c) + b * c > n) {
                        c--; break;
                    }
                }
            }
        }
    }
}