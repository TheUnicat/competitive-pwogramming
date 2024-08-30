//
// Created by TheUnicat on 2024-08-30.
//

#include <iostream>
#include <vector>
using namespace std;

bool coprime(int a, int b) {
    if (b == 0) {
        if (a == 1) return true;
        else return false;
    }

    return coprime(b, a % b);
}

int n_even(int l, int r) {
    if (l == r) return 0;
    if (l % 2 == 0 && r % 2 == 0) return (r - l) / 2 + 1;
    if ((l % 2 == 0 && r & 1) || (r % 2 == 0 && l & 1)) return (r - 1 - l) / 2 + 1;
    else return n_even(l + 1, r - 1);
}

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        cout << ((r - l + 1 - n_even(l, r) / 2) / 3) << endl;
        continue;
        vector<bool> removed(r - l + 1, false);
        int steps = 0;
        for (int j = r; j >= l; j--) {
            if (removed[j - l]) continue;
            for (int m = j - 1; m >= l; m--) {
                if (removed[m - l]) continue;
                if (removed[j - l]) break;
                if (!coprime(m, j)) continue;
                for (int n = m - 1; n >= l; n--) {
                    if (removed[n - l]) continue;
                    if (removed[m - l]) break;
                    if (coprime(m, j) && coprime(n, m) && coprime(n, j)) {
                        removed[j - l] = true;
                        removed[m - l] = true;
                        removed[n - l] = true;
                        steps++;
                    }
                }
            }
        }

        cout << steps << endl;
    }
}