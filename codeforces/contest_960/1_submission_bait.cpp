//
// Created by TheUnicat on 2024-07-20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        vector<int> test_case(length);
        for (int j = 0; j < length; j++) {
            cin >> test_case[j];
        }

        sort(test_case.begin(), test_case.end());
        bool alice_wins = false;
        int current_value = -1;
        for (int j = length - 1; j >= 0; j--) {
            if (current_value == -1) current_value = test_case[j];
            if (test_case[j] == current_value) {
                alice_wins = alice_wins == true ? false : true;
            }
            else {
                if (alice_wins) break;
                current_value = test_case[j];
                alice_wins = true;
            }
        }
        if (!alice_wins) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
}
