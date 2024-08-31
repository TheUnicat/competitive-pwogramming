//
// Created by TheUnicat on 2024-08-10.
//

#include <iostream>
using namespace std;

int a, b;

int add(int one, int two) {
    while (two > 0) {
        int carry = one & two;
        one ^= two;
        two = carry << 1;
    }

    return one;
}

int prod(int one, int two) {
    int c = 0;
    int place = 0;
    while (two > 0) {
        if (two & 1) {
            c = add(c, one << place);
        }
        place++;
        two >>= 1;
    }

    return c;
}

int main() {
    cin >> a >> b;

    int c = prod(a, b);

    cout << c;
}