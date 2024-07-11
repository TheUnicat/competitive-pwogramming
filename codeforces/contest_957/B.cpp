//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int size, k;
        cin >> size >> k;

        long long max = 0;
        long long moves = 0;

        for (int j = 0; j < k; j++) {
            long long num;
            cin >> num;
            if (num > max) {
                max = num;
            }
            moves += 2 * num - 1;
        }

        moves -= 2 * max - 1;

        cout << moves << endl;
    }
}
