//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
using namespace std;

int t;
int area;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int min = 2;
        int max = 999;
        int ans = -1;

        while (max > min) {
            int third = min + (max - min) / 3;
            int second_third = min + 2 * (max - min) / 3;
            cout << "? " << third << " " << second_third << endl;
            cout.flush();
            cin >> area;

            if (area == third * (second_third + 1)) {
                min = third + 1;
                max = second_third;
            }
            else if (area == third * second_third) min = second_third + 1;
            else max = third;
        }

        ans = max;


        cout << "! " << ans << endl;
        cout.flush();
    }
}