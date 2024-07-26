//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int test_case;
        cin >> test_case;
        if (test_case == 2) {
            cout << 1 << endl;
            continue;
        }
        else {
            int cows = test_case / 4;
            test_case -= cows * 4;
            int chickens = test_case / 2;
            cout << cows + chickens << endl;
        }
    }
}