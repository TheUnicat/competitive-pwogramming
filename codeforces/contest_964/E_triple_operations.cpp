//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        ll steps = 0;
        cin >> l >> r;

        int min = l;
        while (min != 0) {
            min /= 3;
            steps++;
        }

        int curr_power_of_three = 0;
        int n_power = 0;
        int current_number = l;

        while (current_number <= r) {
            while (curr_power_of_three < current_number) {
                curr_power_of_three *= 3;
                curr_power_of_three += 2;
                n_power++;
            }

            if (curr_power_of_three >= r) {
                steps += n_power * (r - current_number + 1);
                current_number = r + 1;
            }
            else {
                steps += n_power * ((curr_power_of_three) - current_number + 1);
                current_number = curr_power_of_three + 1;
            }
        }

        cout << steps << endl;
    }
}