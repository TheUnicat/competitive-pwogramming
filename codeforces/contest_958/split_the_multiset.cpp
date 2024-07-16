//
// Created by TheUnicat on 2024-07-15.
//

#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, k;
        cin >> n >> k;
        int steps = 0;
        while (n > 1) {
            if (n > k) n -= k - 1; else n-= k;
            steps++;
        }
        cout << steps << endl;
    }
}