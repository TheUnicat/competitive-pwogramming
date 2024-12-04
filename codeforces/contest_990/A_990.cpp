//
// Created by TheUnicat on 2024-12-02.
//

#include <iostream>
using namespace std;

int t;

bool day_happy[100000];

int main() {
    cin >> t;
    int curr_sum = 1;
    int curr_square = 3;
    while (curr_sum < 100000) {
        day_happy[curr_sum] = true;
        curr_sum = curr_square * curr_square;
        curr_square += 2;
    }

    for (int i = 0; i < t; i++) {
        int n, happy_days = 0;
        int pieces = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            pieces += num;
            if (day_happy[pieces]) happy_days++;
        }

        cout << happy_days << endl;
    }
}
