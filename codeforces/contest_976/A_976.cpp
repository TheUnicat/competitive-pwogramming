//
// Created by TheUnicat on 2024-09-29.
//

#include <iostream>
using namespace std;

int t, n, k;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        int min_ops = 0;
        if (k == 1 || k > n) {
            cout << n << endl;
            continue;
        }

        while (n > 0) {
            if (k > n) {
                min_ops += n;
                break;
            }
            int temp_k = k;
            while (temp_k <= n / k) temp_k *= k;
            n -= temp_k;
            min_ops++;
        }

        cout << min_ops << endl;
    }
}
