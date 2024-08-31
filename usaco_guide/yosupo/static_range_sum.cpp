//
// Created by TheUnicat on 2024-06-30.
//

#include <iostream>
using namespace std;

int n, q;

int main() {
    cin >> n >> q;
    long numbers[n + 1];
    numbers[0] = 0;
    long prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        long num;
        cin >> num;
        prefix_sum += num;
        numbers[i + 1] = prefix_sum;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << numbers[r] - numbers[l] << endl;
    }
}