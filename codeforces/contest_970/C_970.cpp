//
// Created by TheUnicat on 2024-09-03.
//

#include <iostream>
using namespace std;

int t;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        int min_x_moves = x / k;
        if (x % k != 0) min_x_moves++;

        int min_y_moves = y / k;
        if (y % k != 0) min_y_moves++;

        int answer;

        if (min_x_moves > min_y_moves) answer = (min_x_moves - 1) * 2 + 1;
        else answer = min_y_moves * 2;

        cout << answer << endl;
    }
}