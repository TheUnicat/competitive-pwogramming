//
// Created by TheUnicat on 2024-07-15.
//

#include <iostream>
#include <cmath>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, k;
        cin >> n >> k;
        int steps = ceil((float) (n - k) / float() (k - 1));
        if (n - steps * (k - 1) > 1) steps++;
        cout << steps << endl;
    }
}