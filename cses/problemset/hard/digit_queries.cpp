//
// Created by TheUnicat on 2024-06-30.
//

//9 1 digit numbers
//9 spots = 9 x 10^0 x 1
//90 2 digit numbers
//180 spots = 9 x 10^1 x 2
//900 3 digit numbers
//2700 spots = 9 x 10^2 x 3
//interesting

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;

int power(int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        num *= 10;
    }
    return num;
}

int num_at_pos(int pos) {
    int digits = 0;
    int spots = 0;
    int copy_pos = pos;
    while (spots <= pos) {
        digits++;
        spots += 9 * power(digits - 1) * digits;
        if (9 * power(digits - 1) * digits < copy_pos) {
            copy_pos -= 9 * power(digits - 1) * digits;
        }
    }

    int min = power(digits - 1);
    int number = ceil((copy_pos) / digits) - 1;
    int position_in_number = digits - copy_pos % digits - 1;
    int final_number = min + number;
    return to_string(final_number)[position_in_number] - '0';
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << num_at_pos(num) << endl;
    }
}