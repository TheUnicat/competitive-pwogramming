//
// Created by TheUnicat on 2024-08-09.
//

#include <iostream>
using namespace std;

int n;
int sum = 0;

int main() {
    cin >> n;
    int rotations[n];
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num;
        rotations[i] = num;
    }

    int test_case = 0;
    while (test_case < 1 << n) {
        int test_sum = 0;
        for (int i = 0; i < n; i++) {
            if (1 << i & test_case) test_sum += rotations[i];
        }

        if ((test_sum - (sum - test_sum)) % 360 == 0) {
            cout << "YES";
            return 0;
        }
        test_case++;
    }
    cout << "NO";
}

//000 001 010 011 100 101 110 111