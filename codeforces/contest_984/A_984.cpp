//
// Created by TheUnicat on 2024-11-02.
//

#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool solvable = true;
        int n;
        cin >> n;
        int prev_note = -1;
        int new_note;
        cin >> prev_note;
        for (int j = 1; j < n; j++) {
            cin >> new_note;
            if (!(abs(new_note - prev_note) == 5 || abs(new_note - prev_note) == 7)) {
                solvable = false;
            }
            prev_note = new_note;
        }

        if (solvable) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}