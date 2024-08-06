//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
using namespace std;

int t;
int c_1, c_2, c_3, c_4;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int wins = 0;
        cin >> c_1 >> c_2 >> c_3 >> c_4;

        if (c_1 >= c_3) {
            if (c_2 > c_4) wins += 2;
            else if (c_2 == c_4 && c_1 > c_3) wins += 2;
        }

        if (c_1 >= c_4) {
            if (c_2 > c_3) wins += 2;
            else if (c_2 == c_3 && c_1 > c_4) wins += 2;
        }

        cout << wins << endl;
    }
}