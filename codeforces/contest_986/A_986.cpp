//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <string>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b;
        string moves;
        cin >> n >> a >> b;
        cin >> moves;
        int temp_x = 0, temp_y = 0;
        for (int j = 0; j < n; j++) {
            char move = moves[j];
            if (move == 'N') temp_y++;
            else if (move == 'S') temp_y--;
            else if (move == 'W') temp_x--;
            else temp_x++;
        }

        int x = 0, y = 0;
        bool solvable = false;
        for (int k = 0; k < 101; k++) {
            for (int j = 0; j < n; j++) {
                if (a == x && b == y) {
                    solvable = true;
                    break;
                }
                char move = moves[j];
                if (move == 'N') y++;
                else if (move == 'S') y--;
                else if (move == 'W') x--;
                else x++;
            }
        }

        if (solvable) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}