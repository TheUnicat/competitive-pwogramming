//
// Created by TheUnicat on 2024-10-13.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, r;
        int happy = 0;
        int singles = 0;
        cin >> n >> r;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            int doubles = num / 2;
            r -= doubles;
            happy += doubles * 2;
            num -= doubles * 2;

            singles += num;
        }

        if (singles & 1) {
            happy++;
            r--;
            singles--;
        }

        happy += min(r * 2 - singles, singles);

        cout << happy << endl;
    }
}