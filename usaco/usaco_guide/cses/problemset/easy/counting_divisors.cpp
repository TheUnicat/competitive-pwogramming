//
// Created by TheUnicat on 2024-08-21.
//

#include <iostream>
using namespace std;

int t;

int count_divisors(int num) {
    int count = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num) count += 2;
            else count++;
        }
    }

    return count;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        cout << count_divisors(num) << endl;
    }
}