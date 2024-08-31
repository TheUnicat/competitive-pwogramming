//
// Created by TheUnicat on 2024-06-25.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    int evens = 0;
    int odds = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {evens++;} else {odds++;}
    }

    bool current_group_even = true;
    int n_groups = 0;
    if (evens > 0) {
        n_groups += 2 * min(evens, odds);
        evens -= n_groups / 2;
        odds -= n_groups / 2;
    }
    while (true) {
        if (current_group_even) {
            if (evens > 0) {
                evens--;
                n_groups++;
            }
            else if (odds >= 2) {
                odds -= 2;
                n_groups++;
            }
            else {
                break;
            }
            current_group_even = false;
        }
        else {
            if (odds > 0) {
                odds--;
                n_groups++;
            }
            else {
                break;
            }
            current_group_even = true;
        }
    }
    if (odds % 2 == 1) {
        n_groups--;
    }
    cout << n_groups;
}